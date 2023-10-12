#include <ros/ros.h>
#include <my_demo/Greeting.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "greeting_client");   // node name
    ros::NodeHandle nh;                         // create handler
    ros::ServiceClient client = nh.serviceClient<my_demo::Greeting>("greetings");  // service name

    // set request
    my_demo::Greeting srv;
    srv.request.name = "HAN";
    srv.request.age = 20;

    if(client.call(srv)) {
        ROS_INFO( "Feedback from server: %s", srv.response.feedback.c_str());
    } else {
        ROS_ERROR( "Failed to call service greetings.");
        return 1;
    }

    return 0;
}
