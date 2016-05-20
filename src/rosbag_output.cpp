#include <ros/ros.h>
#include "rosbag_output/conversion.h"
#include <geometry_msgs/PoseStamped.h>



void poseCallback(const geometry_msgs::PoseStampedConstPtr& msg)
{
        //geometry_msgs::PoseStamped pose;
        Quaterniond q;
        Vector3d p;
        Vector3d rpy;
        //pose.header.stamp = header.stamp;
        //pose.header.frame_id = "/world";
        q.w() = msg-> pose.orientation.w;
        q.x() = msg-> pose.orientation.x;
        q.y() = msg-> pose.orientation.y;
        q.z() = msg-> pose.orientation.z;
        p(0) = msg -> pose.position.x;
        p(1) = msg -> pose.position.y;
        p(2) = msg -> pose.position.z;
        rpy = quaternion2euler(q);
        cout <<rpy(0)<<" "<<rpy(1)<<" "<<rpy(2)<<" "<<p(0)<<" "<<p(1)<<" "<<p(2)<<endl;
}

int main(int argc, char** argv)
{
        freopen("/home/yebo/yebo/src/rosbag_output/log.txt","w",stdout);
        ros::init(argc,argv,"rosbag_output");
        ros::NodeHandle n;
        //ros::Subscriber sub = n.subscribe("/est_pose",10,poseCallback);
        ros::Subscriber sub = n.subscribe("/ground_truth_to_tf/pose",10,poseCallback);
        ros::spin();
        return 0;
}
