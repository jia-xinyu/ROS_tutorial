#!/usr/bin/env python3
import rospy
from my_demo.srv import Greeting

def handleFunction(req):
    rospy.loginfo( "Request from", req.name, 'with age', req.age)
    return Greeting.Response( 'Hi %s, I am server!', req.name)

def server():
    rospy.init_node( 'greeting_server')
    rospy.Service( 'greetings', Greeting, handleFunction)
    rospy.loginfo( 'Ready to handle the request')
    rospy.spin()

if __name__ == '__main__':
    server()
