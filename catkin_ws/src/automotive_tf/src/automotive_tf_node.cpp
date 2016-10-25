#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
 
int main(int argc, char** argv){
  ros::init(argc, argv, "robot_tf_publisher");
  ros::NodeHandle n;
  
  ros::Rate r(10);
  
  tf::TransformBroadcaster broadcaster;
  
  while(n.ok()){
    broadcaster.sendTransform(
       tf::StampedTransform(
	  tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.09, 0.00, 0.22)),
	  ros::Time::now(), 
	  "base_link",
	  "camera_link"));

    broadcaster.sendTransform(
       tf::StampedTransform(
	  tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.11, 0.00, 0.21)),
	  ros::Time::now(), 
	  "base_link",
	  "StructureSensor/camera_link"));
    
    broadcaster.sendTransform(
       tf::StampedTransform(
	  tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.09, 0.00, 0.12)),
	  ros::Time::now(), 
	  "base_link",
	  "base_imu_link"));
    broadcaster.sendTransform(
       tf::StampedTransform(
	  tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.0, 0, 0)),
	  ros::Time::now(), 
	  "map",
	  "base_link"));    
    broadcaster.sendTransform(
       tf::StampedTransform(
	  tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.0, 0, 0)),
	  ros::Time::now(), 
	  "world",
	  "map"));
    r.sleep();
  }
}
