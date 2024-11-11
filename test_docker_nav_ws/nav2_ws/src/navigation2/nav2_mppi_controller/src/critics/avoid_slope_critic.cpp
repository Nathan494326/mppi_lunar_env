// Copyright (c) 2022 Samsung Research America, @artofnothingness Alexey Budyakov
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "nav2_mppi_controller/critics/avoid_slope_critic.hpp"
#include <fstream>
#include <sstream>
#include <vector>
#include <rclcpp/rclcpp.hpp>
#include <grid_map_msgs/msg/grid_map.hpp>
#include <grid_map_core/grid_map_core.hpp>

namespace mppi::critics
{

void AvoidSlopeCritic::initialize()
{
    auto getParam = parameters_handler_->getParamGetter(name_);
    getParam(power_, "cost_power", 1);
    getParam(weight_, "cost_weight", 5.0);

    RCLCPP_INFO(logger_, "AvoidSlopeCritic instantiated with %d power and %f weight.", power_, weight_);
  
    // Subscribe to the grid map topic
    auto node = parent_.lock(); // Get the node from the weak pointer
    grid_map_subscriber_ = node->create_subscription<grid_map_msgs::msg::GridMap>(
        "gm_topic",  // The topic name where grid maps are published
        rclcpp::SensorDataQoS(),  // QoS settings for sensor data
        std::bind(&AvoidSlopeCritic::gridMapCallback, this, std::placeholders::_1)
    );

    RCLCPP_INFO(logger_, "Subscribed to grid map topic: gm_topic");

    // Initialize the timestamp for the maps
    live_map_timestamp_ = rclcpp::Time(0, 0, RCL_ROS_TIME);
    used_map_timestamp_ = rclcpp::Time(0, 0, RCL_ROS_TIME);
}




void AvoidSlopeCritic::gridMapCallback(const grid_map_msgs::msg::GridMap::SharedPtr msg)
{
    // Update the live map freely
    grid_map_received_ = true;

    // Access the layer where the height data is stored
    std::string layer_name = "elevation";  // Layer name for height data
    live_map_.clear(); // Clear previous data in live_map_

    // Find the index of the layer in the message
    auto it = std::find(msg->layers.begin(), msg->layers.end(), layer_name);
    if (it != msg->layers.end()) {
        int layer_index = std::distance(msg->layers.begin(), it);
        const auto& data = msg->data[layer_index].data;

        // Store the height data directly into the live_map vector
        live_map_.assign(data.begin(), data.end());

        // Update the timestamp of the live_map
        live_map_timestamp_ = msg->header.stamp;

        // RCLCPP_INFO(logger_, "Live map updated with %zu values.", live_map_.size());
    } else {
        RCLCPP_WARN(logger_, "Layer '%s' not found in grid map message.", layer_name.c_str());
    }
}



void AvoidSlopeCritic::score(CriticData & data)
{
    using xt::evaluation_strategy::immediate;
    if (!enabled_ || data.path.x.shape(0) < 2 ||
        utils::withinPositionGoalTolerance(threshold_to_consider_, data.state.pose.pose, data.path))
    {
        return;
    }

    if (!grid_map_received_) {
        RCLCPP_WARN(logger_, "Waiting for grid map. Navigation is paused.");
        return;  // Exit the function until a grid map is received
    }

    float robot_x = data.state.pose.pose.position.x;
    float robot_y = data.state.pose.pose.position.y;

    if (live_map_timestamp_.get_clock_type() == used_map_timestamp_.get_clock_type()) {
        if (live_map_timestamp_ > used_map_timestamp_) {

                used_local_map_ = live_map_;

                used_map_timestamp_ = live_map_timestamp_;
        }
    } else {
        RCLCPP_WARN(logger_, "Cannot compare times with different time sources.");
    }

    auto slope_scores = xt::zeros_like(data.costs);

    // Loop over each trajectory and each pose in the trajectory
    for (size_t i = 0; i < data.trajectories.x.shape(0); ++i) {

        float local_x_pose_t_in_traj_i = data.trajectories.x(i, 0) - robot_x;
        float local_y_pose_t_in_traj_i = data.trajectories.y(i, 0) - robot_y;
 
        int x_index = static_cast<int>((local_x_pose_t_in_traj_i + 4.0) * 5.0); // 4.0 represents half the width of the local map, and 5.0 is 1/resolution
        int y_index = static_cast<int>((local_y_pose_t_in_traj_i - 4.0) * (-5.0)); // 4.0 represents half the height of the local map, and 5.0 is 1/resolution

        if (x_index > 40 || y_index > 40 || x_index < 0 || y_index < 0 ) {
            // RCLCPP_INFO(logger_, "Out of the local map, x : %d", x_index);
            // RCLCPP_INFO(logger_, "Out of the local map, y : %d", y_index);
            break;
        }

        float previous_height = used_local_map_[y_index * 40 + x_index]*1.5;
        float previous_x = local_x_pose_t_in_traj_i;
        float previous_y = local_x_pose_t_in_traj_i;

        for (size_t t = 1; t < data.trajectories.x.shape(1); ++t) {

            local_x_pose_t_in_traj_i = data.trajectories.x(i, t) - robot_x;
            local_y_pose_t_in_traj_i = data.trajectories.y(i, t) - robot_y;

            x_index = static_cast<int>((local_x_pose_t_in_traj_i + 4.0) * 5.0); 
            y_index = static_cast<int>((local_y_pose_t_in_traj_i - 4.0) * (-5.0));

            if (x_index > 40 || y_index > 40 || x_index < 0 || y_index < 0 ) {
                // RCLCPP_INFO(logger_, "Out of the local map, x : %d", x_index);
                // RCLCPP_INFO(logger_, "Out of the local map, y : %d", y_index);
                break;
            }
            float current_height = used_local_map_[y_index * 40 + x_index]*1.5;




            // Computation of the angle of the robot at the specific position

            float height_difference = current_height - previous_height; 

            float d = std::sqrt((previous_x - local_x_pose_t_in_traj_i) * (previous_x - local_x_pose_t_in_traj_i) + 
                                (previous_y - local_y_pose_t_in_traj_i) * (previous_y - local_y_pose_t_in_traj_i));
            float ratio = height_difference / d;

            // Third-order approximation for atan
            float angle = ratio - (ratio * ratio * ratio) / 3.0f + (ratio * ratio * ratio * ratio * ratio) / 5.0f;

            if (previous_x != local_x_pose_t_in_traj_i || previous_y != local_y_pose_t_in_traj_i) {
                slope_scores(i) += angle;  
                if (angle < 0) {
                    slope_scores(i) -= angle;   
                }
            }

            previous_height = current_height;
            previous_x = local_x_pose_t_in_traj_i;
            previous_y = local_x_pose_t_in_traj_i;
        }

        // RCLCPP_INFO(logger_, "score : %f", slope_scores(i));

    }

    data.costs += xt::pow(weight_ * slope_scores, power_);

}

}



#include <pluginlib/class_list_macros.hpp>

PLUGINLIB_EXPORT_CLASS(
  mppi::critics::AvoidSlopeCritic,
  mppi::critics::CriticFunction)
