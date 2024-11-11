
# Copyright 2023 Fictionlab sp. z o.o.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.


import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PythonExpression
from launch_ros.actions import Node


def generate_launch_description():
    # Setup project paths
    pkg_ros_gz_sim = get_package_share_directory("ros_gz_sim")
    pkg_project_gazebo = get_package_share_directory("leo_gz_bringup")
    pkg_project_worlds = get_package_share_directory("leo_gz_worlds")
    sim_world = LaunchConfiguration("sim_world")
    lidar_bridge_config = os.path.join(
      get_package_share_directory('leo_gz_bringup'),
      'config',
      'gz_bridge.yaml'
      )

    sim_world = DeclareLaunchArgument(
        "sim_world",
        default_value=os.path.join(pkg_project_worlds, "worlds", "leo_empty.sdf"),
        description="Path to the Gazebo world file",
    )

    world_frame = DeclareLaunchArgument(
        "world_frame",
        default_value="leo_empty",
        description="Name of the .sdf file",
    )

    robot_ns = DeclareLaunchArgument(
        "robot_ns",
        default_value="",
        description="Robot namespace",
    )

    # Setup to launch the simulator and Gazebo world
    gz_sim = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_ros_gz_sim, "launch", "gz_sim.launch.py")
        ),
        #launch_arguments={"gz_args": LaunchConfiguration("sim_world"), "ign_args":"-s"}.items(),
    	launch_arguments={"gz_args": ['-r -v4 ', LaunchConfiguration("sim_world")], 'on_exit_shutdown': 'true'}.items()
    )

    spawn_robot = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_project_gazebo, "launch", "spawn_robot.launch.py")
        ),
        launch_arguments={"robot_ns": LaunchConfiguration("robot_ns")}.items(),
    )

    # Bridge ROS topics and Gazebo messages for establishing communication
    topic_bridge = Node(
        package="ros_gz_bridge",
        executable="parameter_bridge",
        name="clock_bridge",
        arguments=[
            "/clock@rosgraph_msgs/msg/Clock[ignition.msgs.Clock",
        ],
        parameters=[
            {
                "qos_overrides./tf_static.publisher.durability": "transient_local",
            }
        ],
        output="screen",
    )
    
    lidar_topic_bridge = Node(
        package="ros_gz_bridge",
        executable="parameter_bridge",
        name="lidar_bridge",
        parameters=[
            {
                # "qos_overrides./tf_static.publisher.durability": "transient_local",
                "config_file": lidar_bridge_config,
            }
        ],
        output="screen",
    )

    static_transform_publisher = Node(
        package="tf2_ros",
        executable="static_transform_publisher",
        name="static_transform_publisher",
        arguments=[
            "0", "0", "0",  # x, y, z
            "0", "0", "0", "1",  # qx, qy, qz, qw (quaternion)
            "map",  # parent frame (frame_id)
            "odom"  # child frame (child_frame_id)
        ],
        output="screen",
    )

    # Static transform publisher for map -> leo_empty (or other world name)
    static_transform_publisher_world = Node(
        package="tf2_ros",
        executable="static_transform_publisher",
        name="static_transform_publisher_world",
        arguments=[
            "0", "0", "0",  # x, y, z
            "0", "0", "0", "1",  # qx, qy, qz, qw (quaternion)
            "map",  # parent frame (frame_id)
            LaunchConfiguration("world_frame")  # child frame (extracted world name without .sdf)
        ],
        output="screen",
    )
    
    leo_gt_odom_publisher = Node(
            package='leo_pose',
            executable='gt_odometry',
            name='gt_odometry',
            output='screen'
        )


    return LaunchDescription(
        [
            sim_world,
            robot_ns,
            gz_sim,
            spawn_robot,
            topic_bridge,
            lidar_topic_bridge,
            static_transform_publisher,
            static_transform_publisher_world,
            leo_gt_odom_publisher
        ]
    )
