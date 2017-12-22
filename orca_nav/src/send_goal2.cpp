#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <stdlib.h>
#include <tf/transform_datatypes.h>

int main (int argc, char **argv)
{
ros::init(argc, argv, "publish_goal");
ros::NodeHandle nh;

ros::Publisher pub= nh.advertise<geometry_msgs::PoseStamped>("move_base_simple/goal", 1000);

ros::Rate rate(0.5);

while (ros::ok)
{
	
	geometry_msgs::PoseStamped msg;
	//msg.goal.target_pose.header.frame_id = "base_link";
	//msg.goal.target_pose.header.stamp = ros::Time::now();


msg.pose.position.x= 5;
msg.pose.position.y= 4;


pub.publish(msg);

ROS_INFO_STREAM("Sending goal " << msg.pose.position.x << ", " << msg.pose.position.y<< "\n" );
	
}


return 0;
}
