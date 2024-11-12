// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/Obstacles.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__OBSTACLES__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__OBSTACLES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/obstacles__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_Obstacles_obstacles
{
public:
  explicit Init_Obstacles_obstacles(::custom_msgs::msg::Obstacles & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::Obstacles obstacles(::custom_msgs::msg::Obstacles::_obstacles_type arg)
  {
    msg_.obstacles = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::Obstacles msg_;
};

class Init_Obstacles_timestamp
{
public:
  Init_Obstacles_timestamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Obstacles_obstacles timestamp(::custom_msgs::msg::Obstacles::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_Obstacles_obstacles(msg_);
  }

private:
  ::custom_msgs::msg::Obstacles msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::Obstacles>()
{
  return custom_msgs::msg::builder::Init_Obstacles_timestamp();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__OBSTACLES__BUILDER_HPP_
