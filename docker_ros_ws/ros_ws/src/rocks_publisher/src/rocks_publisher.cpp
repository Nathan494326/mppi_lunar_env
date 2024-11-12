#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "custom_msgs/msg/obstacle_data.hpp"
#include "custom_msgs/msg/obstacles.hpp"
#include "builtin_interfaces/msg/time.hpp"
#include <cmath>
#include <array>
#include <vector>

class RocksPublisher : public rclcpp::Node {
public:
    RocksPublisher() : Node("rocks_publisher") {
        // Initialize rock positions and radii
        rock_positions_ = {
            {3.0, 4.0, 0.3},  // Cylinder 1: (x, y, radius)
            {-5.0, 0.0, 0.5}, // Cylinder 2
            {3.0, -3.0, 0.7}, // Cylinder 3
            {7.5, 7.5, 0.5},  // Cylinder 4
            {0.0, 0.0, 1.1}   // Cylinder 5
        };

        publisher_ = this->create_publisher<custom_msgs::msg::Obstacles>("/rocks_position", 10);
        odom_subscriber_ = this->create_subscription<nav_msgs::msg::Odometry>(
            "/odom", 10, std::bind(&RocksPublisher::odom_callback, this, std::placeholders::_1)
        );

        timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&RocksPublisher::publish_rocks, this));
    }

private:
    void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg) {
        // Store the robot's x and y positions in the buffer
        x_pose_buffer_ = msg->pose.pose.position.x;
        y_pose_buffer_ = msg->pose.pose.position.y;
    }

    void publish_rocks() {
        custom_msgs::msg::Obstacles msg;  // Use custom message type
        msg.obstacles.clear();  // Ensure the obstacle list is empty
        bool rock_within_range = false;

        float x_used = x_pose_buffer_;
        float y_used = y_pose_buffer_;

        // Get the current time and set the timestamp
        rclcpp::Time now = this->get_clock()->now();
        msg.timestamp = now;  // Set the timestamp correctly

        // Check each rock's position and radius
        for (const auto& rock : rock_positions_) {
            float rock_x = rock[0];
            float rock_y = rock[1];
            float rock_radius = rock[2];

            // Calculate distance from the robot to the rock
            float distance = std::sqrt(std::pow(rock_x - x_used, 2) + std::pow(rock_y - y_used, 2));

            // Check if the rock is within 4 meters
            if (distance <= 4.0) {
                custom_msgs::msg::ObstacleData obstacle;  // Create an instance of ObstacleData
                obstacle.x = rock_x;  // Set x position
                obstacle.y = rock_y;  // Set y position
                obstacle.radius = rock_radius;  // Set radius

                msg.obstacles.push_back(obstacle);  // Add the obstacle data to the message
                rock_within_range = true;
            }
        }

        // Publish only if there are rocks within range
        if (rock_within_range) {
            publisher_->publish(msg);
        }
    }

    rclcpp::Publisher<custom_msgs::msg::Obstacles>::SharedPtr publisher_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_subscriber_;
    rclcpp::TimerBase::SharedPtr timer_;

    std::vector<std::array<float, 3>> rock_positions_;  // Store (x, y, radius) for each rock
    float x_pose_buffer_ = 0.0;  // Robot's x position (buffer)
    float y_pose_buffer_ = 0.0;  // Robot's y position (buffer)
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<RocksPublisher>());
    rclcpp::shutdown();
    return 0;
}
