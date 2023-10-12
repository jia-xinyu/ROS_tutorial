#include <ros/ros.h>
#include <roscpp_demo/Greeting.h>

bool handleFunction(roscpp_demo::Greeting::Request &req, roscpp_demo::Greeting::Response &res) {
    // print request
    ROS_INFO( "Request from %s with age %d", req.name.c_str(), req.age);

    // set response
    res.feedback = "Hi" + req.name+ ", I'm server!";
    return true;
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "greeting_server");   // node name
    ros::NodeHandle nh;                         // create handler
    ros::ServiceServer service = nh.advertiseService("greetings", handleFunction);  // service name, callback function
    ros::spin();                                // block
    return 0;
}
