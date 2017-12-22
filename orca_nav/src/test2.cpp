#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
ros::init(argc, argv, "publish_velocity");
ros::NodeHandle nh;

ros::Publisher pub= nh.advertise<geometry_msgs::PoseStamped>("/goal", 1000);

ros::Rate rate(2);

while (ros::ok)
{

geometry_msgs::PoseStamped msg;
msg.pose.position.x= 5;
msg.pose.position.y= 4;

pub.publish(msg);

ROS_INFO_STREAM("Sending goal " << msg.pose.position.x << ", " << msg.pose.position.y<< "\n" );
	
}


return 0;
}
