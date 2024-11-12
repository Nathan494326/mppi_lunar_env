#ifndef NAV2_MPPI_CONTROLLER__CRITICS__AVOID_SLOPE_CRITIC_HPP_
#define NAV2_MPPI_CONTROLLER__CRITICS__AVOID_SLOPE_CRITIC_HPP_

#include "nav2_mppi_controller/critic_function.hpp"
#include "nav2_mppi_controller/tools/utils.hpp"
#include "grid_map_msgs/msg/grid_map.hpp"
#include "rclcpp/rclcpp.hpp"
#include <grid_map_core/grid_map_core.hpp>

namespace mppi::critics
{
class AvoidSlopeCritic : public CriticFunction 
{
public:
  AvoidSlopeCritic() = default;

  void initialize() override;

  void score(CriticData & data) override;

protected:
  void gridMapCallback(const grid_map_msgs::msg::GridMap::SharedPtr msg);


  unsigned int power_{0};
  float weight_{0};
  float threshold_to_consider_{0};
  std::string gradient_map_file_;
  
  // New members for gradient map integration
  std::vector<std::vector<float>> gradient_map_;  // 2D array to store the gradient map
  int map_width_{0};                              // Width of the gradient map
  int map_height_{0};                             // Height of the gradient map

  rclcpp::Subscription<grid_map_msgs::msg::GridMap>::SharedPtr grid_map_subscriber_; // Subscriber to grid map messages
  grid_map_msgs::msg::GridMap latest_grid_map_;  // Store the latest grid map
  bool grid_map_received_ = false;                // Flag to indicate if a grid map has been received
  
  // New members for height maps
  std::vector<float> used_map_;         // 1D array to store height data
  std::vector<float> live_map_;         // 1D array to store height data
  std::vector<float> used_local_map_;   // 1D array to store local height data
  rclcpp::Time live_map_timestamp_;     // Timestamp of the live map
  rclcpp::Time used_map_timestamp_;     // Timestamp of the used map
};

}  // namespace mppi::critics

#endif  // NAV2_MPPI_CONTROLLER__CRITICS__AVOID_SLOPE_CRITIC_HPP_
