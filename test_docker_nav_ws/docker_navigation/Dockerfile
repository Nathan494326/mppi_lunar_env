# Use the OSRF ROS base image
FROM osrf/ros:humble-desktop

# Set the working directory inside the container
WORKDIR /workstation


RUN apt-get update && apt-get install -y \
    ros-${ROS_DISTRO}-bondcpp \
    ros-${ROS_DISTRO}-angles \ 
    ros-${ROS_DISTRO}-geometry2 \ 
    ros-${ROS_DISTRO}-pluginlib \
    ros-${ROS_DISTRO}-tf2 \
    ros-${ROS_DISTRO}-tf2-geometry-msgs \
    ros-${ROS_DISTRO}-tf2-ros \ 
    ros-${ROS_DISTRO}-test-msgs \ 
    ros-${ROS_DISTRO}-rclcpp \
    ros-${ROS_DISTRO}-std-msgs \ 
    ros-${ROS_DISTRO}-visualization-msgs \
    ros-${ROS_DISTRO}-diagnostic-msgs \
    ros-${ROS_DISTRO}-rosbag2 \
    ros-${ROS_DISTRO}-ament-cmake \
    ros-${ROS_DISTRO}-ament-cmake-gmock \
    ros-${ROS_DISTRO}-ament-cmake-gtest \
    ros-${ROS_DISTRO}-ros-base \ 
    ros-${ROS_DISTRO}-behaviortree-cpp-v3 \
    ros-${ROS_DISTRO}-diagnostic-updater \
    ros-${ROS_DISTRO}-grid-map-msgs \
    ros-${ROS_DISTRO}-grid-map-core \
    ros-${ROS_DISTRO}-gazebo-ros-pkgs \
    libceres-dev \
    libompl-dev \
    libgraphicsmagick++1-dev \
    libxtensor-dev \
    && rm -rf /var/lib/apt/lists/* 


# Copy the entrypoint script into the container
COPY ./entrypoint.sh /

# Set the entrypoint to the entrypoint script
ENTRYPOINT ["/entrypoint.sh"]
CMD ["bash"]