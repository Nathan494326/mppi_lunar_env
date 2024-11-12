#include "rclcpp/rclcpp.hpp"
#include "grid_map_msgs/msg/grid_map.hpp"
#include <algorithm>

class GridMapSubscriber : public rclcpp::Node {
public:
    GridMapSubscriber()
    : Node("grid_map_subscriber") {
        // Create a subscription to the grid map topic
        subscription_ = this->create_subscription<grid_map_msgs::msg::GridMap>(
            "/gm_topic", 10,
            std::bind(&GridMapSubscriber::gridMapCallback, this, std::placeholders::_1)
        );
    }

private:
    void gridMapCallback(const grid_map_msgs::msg::GridMap::SharedPtr msg) {
        // Access the layer where the height data is stored
        std::string layer_name = "elevation";  // Use the same layer name as in your publisher
        int height_index = 7436;
        auto it = std::find(msg->layers.begin(), msg->layers.end(), layer_name);
        
        if (it != msg->layers.end()) {
            int layer_index = std::distance(msg->layers.begin(), it);
            const auto& data = msg->data[layer_index].data;

            // Check if we have at least 121 values
            if (data.size() > (height_index-1)) {
                float value = data[height_index-1];
                value = value * 1.5040130184025315;
                RCLCPP_INFO(this->get_logger(), "height value: %f", value);
            } else {
                RCLCPP_WARN(this->get_logger(), "Grid map does not have enough values.");
            }
        } else {
            RCLCPP_WARN(this->get_logger(), "Layer not found in grid map message.");
        }
    }

    rclcpp::Subscription<grid_map_msgs::msg::GridMap>::SharedPtr subscription_;
};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<GridMapSubscriber>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
