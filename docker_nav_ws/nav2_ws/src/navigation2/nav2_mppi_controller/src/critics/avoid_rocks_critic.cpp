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

#include "nav2_mppi_controller/critics/avoid_rocks_critic.hpp"
#include <fstream>
#include <sstream>
#include <vector>
#include <rclcpp/rclcpp.hpp>
#include <grid_map_msgs/msg/grid_map.hpp>
#include <grid_map_core/grid_map_core.hpp>

namespace mppi::critics
{

// Initialization function
void AvoidRocksCritic::initialize()
{
        auto getParam = parameters_handler_->getParamGetter(name_);
        getParam(power_, "cost_power", 1);
        getParam(weight_, "cost_weight", 5.0);
        RCLCPP_INFO(logger_, "AvoidRocksCritic instantiated with %d power and %f weight.", power_, weight_);
        
        auto node = parent_.lock(); // Get the node from the weak pointer

        // Subscribe to rocks position using custom message type
        rocks_position_subscriber_ = node->create_subscription<custom_msgs::msg::Obstacles>(
            "/rocks_position",  // Topic name
            10,  // QoS settings
            std::bind(&AvoidRocksCritic::rocksPositionCallback, this, std::placeholders::_1)
        );

        RCLCPP_INFO(logger_, "Subscribed to rocks position topic: /rocks_position");
}

    // Callback for updating obstacle buffer
void AvoidRocksCritic::rocksPositionCallback(const custom_msgs::msg::Obstacles::SharedPtr msg) 
{   obstacles_buffer_.clear();  // Clear previous data

    // Parse the received Obstacles message
    for (const auto& obstacle : msg->obstacles) {
        float x = obstacle.x;
        float y = obstacle.y;
        float radius = obstacle.radius;
        obstacles_buffer_.emplace_back(std::array<float, 3>{x, y, radius});  // Store obstacle data
    }

    RCLCPP_INFO(logger_, "Updated obstacles buffer with %zu obstacles", obstacles_buffer_.size());
}

    // Score function to compute costs based on robot's trajectory and obstacles
void AvoidRocksCritic::score(CriticData & data) {
    // Check conditions for scoring
    if (!enabled_ || data.path.x.shape(0) < 2 || utils::withinPositionGoalTolerance(threshold_to_consider_, data.state.pose.pose, data.path)) {
        return;
    }

    auto slope_scores = xt::zeros_like(data.costs);

    // Loop over each trajectory and each pose in the trajectory
    for (size_t i = 0; i < data.trajectories.x.shape(0); ++i) {
        bool break_outer_loop = false; // Flag to break out of the outer loop

        for (size_t t = 1; t < data.trajectories.x.shape(1); ++t) {
            float traj_x = data.trajectories.x(i, t);
            float traj_y = data.trajectories.y(i, t);

            for (const auto& obstacle : obstacles_buffer_) {
                float obstacle_x = obstacle[0];
                float obstacle_y = obstacle[1];
                float obstacle_radius = obstacle[2];
                float robot_radius = 0.3;

                float distance = std::sqrt(std::pow(traj_x - obstacle_x, 2) + std::pow(traj_y - obstacle_y, 2));

                if (distance < (obstacle_radius + robot_radius)) {
                    slope_scores(i) += 1000.0;
                    RCLCPP_INFO(logger_, "Obstacle with radius %f detected", obstacle_radius);

                    break_outer_loop = true; // Set the flag to exit both loops
                    break; // Exit the obstacle loop
                } else {
                    slope_scores(i) += (1.0 / distance);
                }
            }

            if (break_outer_loop) break; // Check flag to exit the trajectory points loop
        }
    }

    // Calculate the final costs based on slope scores
    data.costs += xt::pow(weight_ * slope_scores, power_);
}

}  // namespace mppi::critics

#include <pluginlib/class_list_macros.hpp>

PLUGINLIB_EXPORT_CLASS(
  mppi::critics::AvoidRocksCritic,
  mppi::critics::CriticFunction)