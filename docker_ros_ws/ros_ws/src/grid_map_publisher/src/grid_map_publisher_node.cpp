#include "rclcpp/rclcpp.hpp"
#include "grid_map_msgs/msg/grid_map.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "std_msgs/msg/string.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>
#include <yaml-cpp/yaml.h>
#include <fstream>
#include <string>

class GridMapPublisher : public rclcpp::Node {
public:
    GridMapPublisher()
    : Node("grid_map_publisher"), x_pose_buffer_(0.0), y_pose_buffer_(0.0) {
        // Load configuration from YAML file
        std::string config_file = "src/grid_map_publisher/config/grid_map_config.yaml";  // Update this path
        YAML::Node config = YAML::LoadFile(config_file);
        map_file_ = config["map_file"].as<std::string>();
        resolution_ = config["resolution"].as<double>();
        origin_ = config["origin"].as<std::vector<double>>();
        layer_name_ = config["layer_name"].as<std::string>();

        // Publisher
        publisher_ = this->create_publisher<grid_map_msgs::msg::GridMap>("/gm_topic", 10);

        // Subscriber to /odom topic
        odom_subscriber_ = this->create_subscription<nav_msgs::msg::Odometry>(
            "/odom", 10, std::bind(&GridMapPublisher::odomCallback, this, std::placeholders::_1)
        );

        // Load image
        cv::Mat height_map = cv::imread(map_file_, cv::IMREAD_GRAYSCALE);
        if (height_map.empty()) {
            RCLCPP_ERROR(this->get_logger(), "Failed to load height map image.");
            return;
        }

        // Create grid map
        createGridMap(height_map);

        

        // Timer to publish the grid map periodically
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(500), 
            std::bind(&GridMapPublisher::publishGridMap, this)
        );
    }

private:
    void odomCallback(const nav_msgs::msg::Odometry::SharedPtr msg) {
        // Store the current robot position from the odometry message
        x_pose_buffer_ = msg->pose.pose.position.x;
        y_pose_buffer_ = msg->pose.pose.position.y;
    }

    void createGridMap(const cv::Mat& height_map) {
        // Populate GridMap message
        grid_map_.info.resolution = resolution_;
        grid_map_.info.length_x = height_map.cols * resolution_;
        grid_map_.info.length_y = height_map.rows * resolution_;
        grid_map_.info.pose.position.x = origin_[0];
        grid_map_.info.pose.position.y = origin_[1];

        grid_map_.header.stamp = this->get_clock()->now();
        grid_map_.header.frame_id = "map";
        grid_map_.layers.push_back(layer_name_);

        // Normalize and convert image data to grid map layer
        cv::Mat normalized_map;
        height_map.convertTo(normalized_map, CV_32F, 1.0 / 255.0);
        flattened_data = std::vector<float>(normalized_map.begin<float>(), normalized_map.end<float>());

    }

    void get_local_subset(const std::vector<float>& grid_map_data, 
                                        double robot_x, double robot_y) {
        // Constants
        const int map_size = 100;         // 100x100 grid
        const int local_size = 40;        // 40x40 local grid
        const int half_local_size = 20;   // Half of the local grid size

        // Calculate the center index in the full map based on robot's position
        int center_x_index = static_cast<int>((robot_x + 10.0) * 5.0);
        int center_y_index = static_cast<int>((robot_y - 10.0) * (-5.0));
    
        // Resulting local map
        std::vector<float> local_subset(local_size * local_size, 0.0f);

        // Loop over the local map area
        for (int i = 0; i < local_size; ++i) {
            for (int j = 0; j < local_size; ++j) {
                // Calculate corresponding index in the full map
                int full_map_x = center_x_index - half_local_size + j;
                int full_map_y = center_y_index - half_local_size + i;

                // Check if the indices are within bounds
                if (full_map_x >= 0 && full_map_x < map_size &&
                    full_map_y >= 0 && full_map_y < map_size) {
                    // Transfer the value from the full map to the local map
                    local_subset[i * local_size + j] = grid_map_data[full_map_y * map_size + full_map_x];
                } else {
                    // If out of bounds, use a default value (e.g., 0.0)
                    local_subset[i * local_size + j] = 12345.0f;
                    // RCLCPP_INFO(this->get_logger(), "OUTSIDE OF THE MAP, x: %d", full_map_x);
                    // RCLCPP_INFO(this->get_logger(), "OUTSIDE OF THE MAP, y: %d", full_map_y);            
                }
            }
        }

        // Convert local_subset to Float32MultiArray
        std_msgs::msg::Float32MultiArray float_array;
        float_array.data = local_subset;

        // Add the layer name and the converted Float32MultiArray to the GridMap message
        grid_map_.data.push_back(float_array);
        // RCLCPP_INFO(this->get_logger(), "Published grid map");
    }


    void publishGridMap() {
        // Update the header timestamp
        grid_map_.header.stamp = this->get_clock()->now();

        double x_pose = x_pose_buffer_;
        double y_pose = y_pose_buffer_;
        // RCLCPP_INFO(this->get_logger(), "x_position is : %f", x_pose);
        // RCLCPP_INFO(this->get_logger(), "y_position is : %f", y_pose);

        grid_map_.data.clear();
        // Get a local subset of the grid map data around the robot's current position
        get_local_subset(flattened_data, x_pose, y_pose);

        // Publish the GridMap message
        publisher_->publish(grid_map_);
        // RCLCPP_INFO(this->get_logger(), "Published grid map");
    }

    // Member variables
    rclcpp::Publisher<grid_map_msgs::msg::GridMap>::SharedPtr publisher_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_subscriber_;
    rclcpp::TimerBase::SharedPtr timer_;
    grid_map_msgs::msg::GridMap grid_map_;
    std::string map_file_;
    double resolution_;
    std::vector<double> origin_;
    std::string layer_name_;
    double x_pose_buffer_; // Buffer to store the current x position
    double y_pose_buffer_; // Buffer to store the current y position
    std::vector<float> flattened_data;
};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<GridMapPublisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
