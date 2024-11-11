// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msgs:msg/Obstacles.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__OBSTACLES__STRUCT_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__OBSTACLES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"
// Member 'obstacles'
#include "custom_msgs/msg/detail/obstacle_data__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_msgs__msg__Obstacles __attribute__((deprecated))
#else
# define DEPRECATED__custom_msgs__msg__Obstacles __declspec(deprecated)
#endif

namespace custom_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Obstacles_
{
  using Type = Obstacles_<ContainerAllocator>;

  explicit Obstacles_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_init)
  {
    (void)_init;
  }

  explicit Obstacles_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : timestamp(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _timestamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _timestamp_type timestamp;
  using _obstacles_type =
    std::vector<custom_msgs::msg::ObstacleData_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_msgs::msg::ObstacleData_<ContainerAllocator>>>;
  _obstacles_type obstacles;

  // setters for named parameter idiom
  Type & set__timestamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__obstacles(
    const std::vector<custom_msgs::msg::ObstacleData_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_msgs::msg::ObstacleData_<ContainerAllocator>>> & _arg)
  {
    this->obstacles = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msgs::msg::Obstacles_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msgs::msg::Obstacles_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msgs::msg::Obstacles_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msgs::msg::Obstacles_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::Obstacles_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::Obstacles_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::Obstacles_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::Obstacles_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msgs::msg::Obstacles_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msgs::msg::Obstacles_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msgs__msg__Obstacles
    std::shared_ptr<custom_msgs::msg::Obstacles_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msgs__msg__Obstacles
    std::shared_ptr<custom_msgs::msg::Obstacles_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Obstacles_ & other) const
  {
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->obstacles != other.obstacles) {
      return false;
    }
    return true;
  }
  bool operator!=(const Obstacles_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Obstacles_

// alias to use template instance with default allocator
using Obstacles =
  custom_msgs::msg::Obstacles_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__OBSTACLES__STRUCT_HPP_
