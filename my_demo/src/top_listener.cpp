#include <ros/ros.h>
#include <my_demo/gps.h>
#include <std_msgs/Float32.h>

void gpsCallback(const my_demo::gps::ConstPtr &msg) {   // &- reference not pointer here, const &- constant reference
    std_msgs::Float32 distance;         // recommend to use ros type "Float32", only a member "data"
    distance.data = sqrt(pow(msg->x,2)+pow(msg->y,2));
    ROS_INFO( "Listener: Distance to origin = %f, state = %s", distance.data, msg->state.c_str());
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "listener");  // node name
    ros::NodeHandle n;                  // create handler
    ros::Subscriber sub = n.subscribe("gps_info", 1, gpsCallback);  // topic name, buffer, callback function
    ros::spin();                        // block
    return 0;
}
