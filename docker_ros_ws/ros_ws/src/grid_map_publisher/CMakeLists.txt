cmake_minimum_required(VERSION 3.8)
project(grid_map_publisher)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(grid_map_msgs REQUIRED)
find_package(grid_map_core REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)
find_package(yaml-cpp REQUIRED)


include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(grid_map_publisher_node src/grid_map_publisher_node.cpp)
ament_target_dependencies(grid_map_publisher_node rclcpp grid_map_msgs sensor_msgs std_msgs cv_bridge OpenCV yaml-cpp nav_msgs)
add_executable(grid_map_subscriber_node src/grid_map_subscriber_node.cpp)
ament_target_dependencies(grid_map_subscriber_node rclcpp grid_map_msgs)

target_link_libraries(grid_map_publisher_node yaml-cpp)

install(TARGETS
  grid_map_publisher_node
  DESTINATION lib/${PROJECT_NAME})
  install(TARGETS
  grid_map_subscriber_node
  DESTINATION lib/${PROJECT_NAME}
)
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
