#ifndef NAV2_MPPI_CONTROLLER__CRITICS__AVOID_ROCKS_CRITIC_HPP_
#define NAV2_MPPI_CONTROLLER__CRITICS__AVOID_ROCKS_CRITIC_HPP_

#include "nav2_mppi_controller/critic_function.hpp"
#include "nav2_mppi_controller/tools/utils.hpp"
#include "rclcpp/rclcpp.hpp"
#include <vector>
#include <array>
#include <custom_msgs/msg/obstacles.hpp> 

namespace mppi::critics
{

class AvoidRocksCritic : public CriticFunction 
{
public:
  // Constructor
  AvoidRocksCritic() = default;

  // Initializes the critic by setting parameters and subscribing to topics
  void initialize() override;

  // Scores the trajectories based on obstacles
  void score(CriticData & data) override;

protected:
  // Parameters for scoring
  unsigned int power_{0};
  float weight_{0};
  float threshold_to_consider_{0};


  // Buffer to store obstacle data as {x, y, radius}
  std::vector<std::array<float, 3>> obstacles_buffer_;  

  // Subscriber for rocks position using custom message type
  rclcpp::Subscription<custom_msgs::msg::Obstacles>::SharedPtr rocks_position_subscriber_;
  void rocksPositionCallback(const custom_msgs::msg::Obstacles::SharedPtr msg);

};

}  // namespace mppi::critics

#endif  // NAV2_MPPI_CONTROLLER__CRITICS__AVOID_ROCKS_CRITIC_HPP_
