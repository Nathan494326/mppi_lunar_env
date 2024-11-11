# Use the OSRF ROS base image
FROM osrf/ros:humble-desktop

# Set the working directory inside the container
WORKDIR /workstation

# Install ROS 2 packages and Gazebo dependencies
RUN apt-get update && apt-get upgrade -y \
    && apt-get install -y \
    python3-colcon-common-extensions \
    ros-${ROS_DISTRO}-desktop \
    ros-${ROS_DISTRO}-grid-map-msgs \
    ros-${ROS_DISTRO}-grid-map-core \
    lsb-release \
    wget \
    gnupg \
    ros-${ROS_DISTRO}-ros-gz-sim \
    vim \
    python3-pip \
    ros-${ROS_DISTRO}-xacro \
    ros-${ROS_DISTRO}-ros-gz-bridge \
    ros-${ROS_DISTRO}-ros-gz-image \
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
    libignition-fuel-tools7-dev \
    libignition-gazebo6-dev \
    && rm -rf /var/lib/apt/lists/*

# Add Ignition (Gazebo) Fortress dependencies
RUN wget https://packages.osrfoundation.org/gazebo.gpg -O /usr/share/keyrings/pkgs-osrf-archive-keyring.gpg && \
    echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/pkgs-osrf-archive-keyring.gpg] http://packages.osrfoundation.org/gazebo/ubuntu-stable $(lsb_release -cs) main" > /etc/apt/sources.list.d/gazebo-stable.list && \
    apt-get update && \
    apt-get install -y ignition-fortress && \
    rm -rf /var/lib/apt/lists/*

RUN ln -s /usr/lib/x86_64-linux-gnu/libignition-fuel-tools7.so.7.3.1 /usr/lib/x86_64-linux-gnu/libignition-fuel_tools7.so.7.3.1

# Copy the entrypoint script into the container
COPY ./entrypoint.sh /

# Set the entrypoint to the entrypoint script
ENTRYPOINT ["/entrypoint.sh"]
CMD ["bash"]

