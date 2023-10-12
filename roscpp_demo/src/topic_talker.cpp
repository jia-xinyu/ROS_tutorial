#include <ros/ros.h>
#include <roscpp_demo/gps.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "talker");    // node name
    ros::NodeHandle nh;                 // create handler
    roscpp_demo::gps msg;                // create msg
    msg.x = 1.0;
    msg.y = 1.0;
    msg.state = "working";
    ros::Publisher pub = nh.advertise<roscpp_demo::gps>("gps_info", 1);  // topic name, buffer

    ros::Rate loop_rate(1.0);           // 1 Hz
    while(ros::ok) {
        msg.x = 1.03 * msg.x;
        msg.y = 1.01 * msg.y;
        ROS_INFO( "talker: GPS: x = %f, y= %f", msg.x, msg.y);          // printf, cout
        pub.publish(msg);
        loop_rate.sleep();              // keep given frequency
    }
    return 0;
}
