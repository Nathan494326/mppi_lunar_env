// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/ObstacleData.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__OBSTACLE_DATA__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__OBSTACLE_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ObstacleData in the package custom_msgs.
/**
  * ObstacleData.msg
 */
typedef struct custom_msgs__msg__ObstacleData
{
  /// x position of the obstacle
  float x;
  /// y position of the obstacle
  float y;
  /// radius of the obstacle
  float radius;
} custom_msgs__msg__ObstacleData;

// Struct for a sequence of custom_msgs__msg__ObstacleData.
typedef struct custom_msgs__msg__ObstacleData__Sequence
{
  custom_msgs__msg__ObstacleData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__ObstacleData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__OBSTACLE_DATA__STRUCT_H_
