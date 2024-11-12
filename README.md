https://github.com/user-attachments/assets/baf1b27b-beb9-41a7-8fb0-677c913d4eda


# Introduction

This project involves navigating a Leo Rover on a simulated lunar terrain using an MPPI controller. The robot uses ROS2 for its software architecture, Gazebo Ignition is used as a simulation environment, and RViz2 as a visualization tool.

As a first step, the terrain topography is simplified to a 2.5D smooth surface, and the rocks are represented by cylinders disposed at strategic places. Using the Nav2stack source code as a baseline, the MPPI controller implementation was modified to incorporate terrain topography as an additional constraint. Since this approach involved using the LiDAR to map the 2.5D surface surrounding the robot, the existing obstacle avoidance constraint became ineffective. Consequently, it had to be reimplemented from scratch using a different algorithmic logic.

In order to be able to put the focus on the navigation part, the localization of the robot is assumed to be known.

---

# Packages Overview

- **`leo_gz_bringup`**:  
  This package handles the Gazebo simulation that contains a 20m x 20m map with a 2.5D surface, the Leo Rover, and cylinders as obstacles. It also includes the node publishing the ground truth odometry of the robot.

- **`grid_map_publisher`**:  
  As the mapping algorithm is assumed to be working, this package (and node) is responsible for publishing the local elevation map. To do so, the robot's current position is retrieved, and a local elevation map of 4m x 4m is published.

- **`rocks_publisher`**:  
  Since obstacle detection is assumed to be working, this package (and node) is responsible for publishing the detected obstacles data. Based on the robot's current position, the x-y position and radius of obstacles within a 4m radius are published.

- **`nav2_bringup`**:  
  This package contains the launch file that launches several nodes from the navigation stack that handle global mapping, local mapping (MPPI controller), velocity smoothing, and more.

---

# Get set up
- Clone the repository where you want it to be on your local machine:
   ```bash
   git clone https://github.com/Nathan494326/mppi_lunar_env.git
   ```
- If not installed yet, install docker on your computer

- Open five terminals, and in four of them go to ```cd /mppi_lunar_env/docker_ros_ws/``` and in the last one, go to ```cd /mppi_lunar_env/docker_nav_ws/``` 

---

# Docker Installation

This section explains how to open 5 different docker containers in order to run everything.

## Terminal 1

- Build the simulation docker:
   ```bash
   ./docker_simulation/build.sh
   ```
- Open a first container of that docker image:
   ```bash
   ./docker_simulation/run.sh -n container1
   ```

## Terminal 2

- Open a second container of the simulation docker image:
   ```bash
   ./docker_simulation/run.sh -n container2
   ```

## Terminal 3

- Open a third container of the simulation docker image:
   ```bash
   ./docker_simulation/run.sh -n container3
   ```

## Terminal 4

- Open a fourth container of the simulation docker image:
   ```bash
   ./docker_simulation/run.sh -n container4
   ```

## Terminal 5

- Build the navigation docker:
   ```bash
   ./docker_navigation/build.sh
   ```
- Open a container of the navigation docker image:
   ```bash
   ./docker_navigation/run.sh
   ```
---

# Execution Instructions

Now that you have opened the containers in each terminal, follow the instructions below to set up and run the ROS2 simulation. 

## Terminal 1

- Navigate to the ROS workspace:
   ```bash
   cd ros_ws
   ```
- Build the workspace (can take around 1min):
   ```bash
   colcon build
   ```
- Source the workspace:
   ```bash
   source install/setup.bash
   ```
- Launch the simulation:
   ```bash
   ros2 launch leo_gz_bringup leo_gz.launch.py sim_world:="/workstation/ros_ws/src/leo_simulator-ros2/leo_gz_worlds/worlds/leo_mountains.sdf" world_frame:="leo_mountains"
   ```

## Terminal 2
- Navigate to the ROS workspace:
   ```bash
   cd ros_ws
   ```
- Launch RViz:
   ```bash
   rviz2 -d test_blank_map.rviz
   ```

## Terminal 3

- Navigate to the ROS workspace:
   ```bash
   cd ros_ws
   ```
- Source the workspace:
   ```bash
   source install/setup.bash
   ```
- Run the grid map publisher:
   ```bash
   ros2 run grid_map_publisher grid_map_publisher_node
   ```

## Terminal 4

- Navigate to the ROS workspace:
   ```bash
   cd ros_ws
   ```
- Source the workspace:
   ```bash
   source install/setup.bash
   ```
- Run the rocks publisher:
   ```bash
   ros2 run rocks_publisher rocks_publisher
   ```

## Terminal 5

- Navigate to the Nav2 workspace:
   ```bash
   cd nav2_ws
   ```
- Build the workspace (this takes a long time, up to 15-20min):
   ```bash
   colcon build
   ```
- Source the workspace:
   ```bash
   source install/setup.bash
   ```
- Launch the navigation stack:
   ```bash
   ros2 launch nav2_bringup map_and_nav_launch.py map:=/workstation/nav2_ws/blank_map.yaml use_sim_time:=true autostart:=true
   ```

