# Introduction

This project involves navigating a Leo Rover on a simulated lunar terrain using an MPPI controller. The robot uses ROS2 for its software architecture, Gazebo Ignition is used as a simulation environment, and RViz2 as a visualization tool.

As a first step, the terrain topography is simplified to a 2.5D smooth surface, and the rocks are represented by cylinders disposed at strategic places. Using the Nav2stack source code as a baseline, the MPPI controller implementation was modified to incorporate terrain topography as an additional constraint. Since that implied using the LiDAR to map the 2.5D surface surrounding the robot, the obstacle detection had to be reimplemented too, so that it now uses camera detection.

In order to be able to put the focus on the navigation part, the localization of the robot is assumed to be known.

## Nodes Overview

- **`leo_gz_bringup`**:  
  Launches a Gazebo simulation that contains a 20m x 20m map with a 2.5D surface, the Leo Rover, and cylinders as obstacles. This node also publishes the ground truth odometry of the robot.

- **`grid_map_publisher`**:  
  As the mapping algorithm is assumed to be working, this node is responsible for publishing the local elevation map. To do so, the robot's current position is retrieved, and a local elevation map of 4m x 4m is published.

- **`rocks_publisher`**:  
  Since obstacle detection is assumed to be working, this node is responsible for publishing the detected obstacles data. Based on the robot's current position, the x-y position and radius of obstacles within a 4m radius are published.

- **`nav2_bringup`** (`launch: map_and_nav_launch.py`):  
  Launches several nodes from the navigation stack that handle global mapping, local mapping (MPPI controller), velocity smoothing, and more.

---

## Docker Installation

### Terminal 1

- Navigate to the ROS workspace:
   ```bash
   cd ros_ws
   ```
- Build the workspace:
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

### Terminal 2

- Launch RViz:
   ```bash
   rviz2 -d test_blank_map.rviz
   ```

### Terminal 3

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

### Terminal 4

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

### Terminal 5

- Navigate to the Nav2 workspace:
   ```bash
   cd nav2_ws
   ```
- Build the workspace:
   ```bash
   colcon build
   ```
- Source the workspace:
   ```bash
   source install/setup.bash
   ```
- Navigate to the ROS2 workspace:
   ```bash
   cd ros2_ws
   ```
- Source the workspace:
   ```bash
   source install/setup.bash
   ```
- Launch the navigation stack:
   ```bash
   ros2 launch nav2_bringup map_and_nav_launch.py map:=/workstation/nav2_ws/blank_map.yaml use_sim_time:=true autostart:=true
   ```

## Execution Instructions

Follow the instructions below to set up and run the ROS2 simulation.

### Terminal 1

- Navigate to the ROS workspace:
   ```bash
   cd ros_ws
   ```
- Build the workspace:
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

### Terminal 2

- Launch RViz:
   ```bash
   rviz2 -d test_blank_map.rviz
   ```

### Terminal 3

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

### Terminal 4

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

### Terminal 5

- Navigate to the Nav2 workspace:
   ```bash
   cd nav2_ws
   ```
- Build the workspace:
   ```bash
   colcon build
   ```
- Source the workspace:
   ```bash
   source install/setup.bash
   ```
- Navigate to the ROS2 workspace:
   ```bash
   cd ros2_ws
   ```
- Source the workspace:
   ```bash
   source install/setup.bash
   ```
- Launch the navigation stack:
   ```bash
   ros2 launch nav2_bringup map_and_nav_launch.py map:=/workstation/nav2_ws/blank_map.yaml use_sim_time:=true autostart:=true
   ```

