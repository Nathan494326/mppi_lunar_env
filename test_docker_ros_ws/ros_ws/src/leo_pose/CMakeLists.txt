cmake_minimum_required(VERSION 3.5)
project(leo_pose)

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

ament_auto_add_library(leo_pose SHARED
  src/gt_odometry.cpp)


ament_auto_add_executable(gt_odometry
  src/gt_odometry.cpp
)

ament_target_dependencies(gt_odometry
    rclcpp
    geometry_msgs
    nav_msgs
    tf2_ros  # Add this line
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_auto_package(
  INSTALL_TO_SHARE
    launch
)

