// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/ObstacleData.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__OBSTACLE_DATA__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__OBSTACLE_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/obstacle_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_ObstacleData_radius
{
public:
  explicit Init_ObstacleData_radius(::custom_msgs::msg::ObstacleData & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::ObstacleData radius(::custom_msgs::msg::ObstacleData::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::ObstacleData msg_;
};

class Init_ObstacleData_y
{
public:
  explicit Init_ObstacleData_y(::custom_msgs::msg::ObstacleData & msg)
  : msg_(msg)
  {}
  Init_ObstacleData_radius y(::custom_msgs::msg::ObstacleData::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_ObstacleData_radius(msg_);
  }

private:
  ::custom_msgs::msg::ObstacleData msg_;
};

class Init_ObstacleData_x
{
public:
  Init_ObstacleData_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObstacleData_y x(::custom_msgs::msg::ObstacleData::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_ObstacleData_y(msg_);
  }

private:
  ::custom_msgs::msg::ObstacleData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::ObstacleData>()
{
  return custom_msgs::msg::builder::Init_ObstacleData_x();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__OBSTACLE_DATA__BUILDER_HPP_
