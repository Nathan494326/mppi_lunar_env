// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from custom_msgs:msg/ObstacleData.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__OBSTACLE_DATA__FUNCTIONS_H_
#define CUSTOM_MSGS__MSG__DETAIL__OBSTACLE_DATA__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "custom_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "custom_msgs/msg/detail/obstacle_data__struct.h"

/// Initialize msg/ObstacleData message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * custom_msgs__msg__ObstacleData
 * )) before or use
 * custom_msgs__msg__ObstacleData__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
bool
custom_msgs__msg__ObstacleData__init(custom_msgs__msg__ObstacleData * msg);

/// Finalize msg/ObstacleData message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
void
custom_msgs__msg__ObstacleData__fini(custom_msgs__msg__ObstacleData * msg);

/// Create msg/ObstacleData message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * custom_msgs__msg__ObstacleData__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
custom_msgs__msg__ObstacleData *
custom_msgs__msg__ObstacleData__create();

/// Destroy msg/ObstacleData message.
/**
 * It calls
 * custom_msgs__msg__ObstacleData__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
void
custom_msgs__msg__ObstacleData__destroy(custom_msgs__msg__ObstacleData * msg);

/// Check for msg/ObstacleData message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
bool
custom_msgs__msg__ObstacleData__are_equal(const custom_msgs__msg__ObstacleData * lhs, const custom_msgs__msg__ObstacleData * rhs);

/// Copy a msg/ObstacleData message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
bool
custom_msgs__msg__ObstacleData__copy(
  const custom_msgs__msg__ObstacleData * input,
  custom_msgs__msg__ObstacleData * output);

/// Initialize array of msg/ObstacleData messages.
/**
 * It allocates the memory for the number of elements and calls
 * custom_msgs__msg__ObstacleData__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
bool
custom_msgs__msg__ObstacleData__Sequence__init(custom_msgs__msg__ObstacleData__Sequence * array, size_t size);

/// Finalize array of msg/ObstacleData messages.
/**
 * It calls
 * custom_msgs__msg__ObstacleData__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
void
custom_msgs__msg__ObstacleData__Sequence__fini(custom_msgs__msg__ObstacleData__Sequence * array);

/// Create array of msg/ObstacleData messages.
/**
 * It allocates the memory for the array and calls
 * custom_msgs__msg__ObstacleData__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
custom_msgs__msg__ObstacleData__Sequence *
custom_msgs__msg__ObstacleData__Sequence__create(size_t size);

/// Destroy array of msg/ObstacleData messages.
/**
 * It calls
 * custom_msgs__msg__ObstacleData__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
void
custom_msgs__msg__ObstacleData__Sequence__destroy(custom_msgs__msg__ObstacleData__Sequence * array);

/// Check for msg/ObstacleData message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
bool
custom_msgs__msg__ObstacleData__Sequence__are_equal(const custom_msgs__msg__ObstacleData__Sequence * lhs, const custom_msgs__msg__ObstacleData__Sequence * rhs);

/// Copy an array of msg/ObstacleData messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
bool
custom_msgs__msg__ObstacleData__Sequence__copy(
  const custom_msgs__msg__ObstacleData__Sequence * input,
  custom_msgs__msg__ObstacleData__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__OBSTACLE_DATA__FUNCTIONS_H_
