#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/msg/transform_stamped.hpp"

class PoseToOdom : public rclcpp::Node
{
public:
    PoseToOdom() : Node("pose_to_odom")
    {
        // Subscribe to the /model/leo_rover/pose topic
        pose_subscriber_ = this->create_subscription<geometry_msgs::msg::PoseStamped>(
            "/model/leo_rover/pose",  
            10,
            std::bind(&PoseToOdom::pose_callback, this, std::placeholders::_1)
        );

        // Publisher for the /odom topic
        odom_publisher_ = this->create_publisher<nav_msgs::msg::Odometry>(
            "/odom",  
            10
        );

        // Initialize TF broadcaster
        tf_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(this);

        RCLCPP_INFO(this->get_logger(), "Pose to Odom node has been started");
    }

private:
    void pose_callback(const geometry_msgs::msg::PoseStamped::SharedPtr pose_msg)
    {
        // Create an Odometry message
        nav_msgs::msg::Odometry odom_msg;

        // Set the header (use same header from the PoseStamped message)
        odom_msg.header.stamp = pose_msg->header.stamp;
        odom_msg.header.frame_id = pose_msg->header.frame_id;  // Typically 'odom'

        // Set the pose part of the Odometry message
        odom_msg.pose.pose = pose_msg->pose;

        // Optionally, set the twist (linear and angular velocities) to zero
        odom_msg.twist.twist.linear.x = 0.0;
        odom_msg.twist.twist.linear.y = 0.0;
        odom_msg.twist.twist.linear.z = 0.0;
        odom_msg.twist.twist.angular.x = 0.0;
        odom_msg.twist.twist.angular.y = 0.0;
        odom_msg.twist.twist.angular.z = 0.0;

        // Optionally, set the covariance matrices for pose and twist
        odom_msg.pose.covariance = {
            0.1, 0, 0, 0, 0, 0,
            0, 0.1, 0, 0, 0, 0,
            0, 0, 0.1, 0, 0, 0,
            0, 0, 0, 0.1, 0, 0,
            0, 0, 0, 0, 0.1, 0,
            0, 0, 0, 0, 0, 0.1
        };

        odom_msg.twist.covariance = {
            0.1, 0, 0, 0, 0, 0,
            0, 0.1, 0, 0, 0, 0,
            0, 0, 0.1, 0, 0, 0,
            0, 0, 0, 0.1, 0, 0,
            0, 0, 0, 0, 0.1, 0,
            0, 0, 0, 0, 0, 0.1
        };

        // Publish the odometry message on the /odom topic
        odom_publisher_->publish(odom_msg);

        // Create a transform message for base_footprint
        geometry_msgs::msg::TransformStamped transform_msg;
        transform_msg.header.stamp = pose_msg->header.stamp; // Same timestamp as the pose message
        transform_msg.header.frame_id = pose_msg->header.frame_id; // Typically 'odom'
        transform_msg.child_frame_id = "base_footprint"; // The frame for which we are publishing the transform

        // Set the transform translation and rotation from the pose message
        transform_msg.transform.translation.x = pose_msg->pose.position.x;
        transform_msg.transform.translation.y = pose_msg->pose.position.y;
        transform_msg.transform.translation.z = pose_msg->pose.position.z;

        transform_msg.transform.rotation = pose_msg->pose.orientation;

        // Publish the transform
        tf_broadcaster_->sendTransform(transform_msg);

        // Uncomment the next line if you want logging
        // RCLCPP_INFO(this->get_logger(), "Published Odometry message and transform");
    }

    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr pose_subscriber_;
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_publisher_;
    std::shared_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    
    auto node = std::make_shared<PoseToOdom>(); 

    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
