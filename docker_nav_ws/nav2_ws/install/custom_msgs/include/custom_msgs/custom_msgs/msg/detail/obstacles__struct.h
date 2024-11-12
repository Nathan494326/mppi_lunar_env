// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/Obstacles.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__OBSTACLES__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__OBSTACLES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__struct.h"
// Member 'obstacles'
#include "custom_msgs/msg/detail/obstacle_data__struct.h"

/// Struct defined in msg/Obstacles in the package custom_msgs.
/**
  * Obstacles.msg
 */
typedef struct custom_msgs__msg__Obstacles
{
  /// Timestamp of the message
  builtin_interfaces__msg__Time timestamp;
  /// Array of obstacles, each with x, y, and radius
  custom_msgs__msg__ObstacleData__Sequence obstacles;
} custom_msgs__msg__Obstacles;

// Struct for a sequence of custom_msgs__msg__Obstacles.
typedef struct custom_msgs__msg__Obstacles__Sequence
{
  custom_msgs__msg__Obstacles * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__Obstacles__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__OBSTACLES__STRUCT_H_
