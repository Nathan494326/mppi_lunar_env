cmake_minimum_required(VERSION 3.8)
project(rocks_publisher)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(custom_msgs REQUIRED)  # Add this line

# Define the rocks_publisher_node executable
add_executable(rocks_publisher src/rocks_publisher.cpp)
ament_target_dependencies(rocks_publisher
  rclcpp
  nav_msgs
  std_msgs
  custom_msgs
)

# Install the executable
install(TARGETS
  rocks_publisher
  DESTINATION lib/${PROJECT_NAME}
)

# If building tests
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # The following line skips the linter which checks for copyrights
  # Comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # The following line skips cpplint (only works in a git repo)
  # Comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
