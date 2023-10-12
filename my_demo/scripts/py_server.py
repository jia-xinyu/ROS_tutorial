#!/usr/bin/env python3
import rospy
from my_demo.srv import *

def handleFunction(req):
    rospy.loginfo( 'Request from %s with age %d' % (req.name, req.age))
    return GreetingResponse( 'Hi %s, I am server!' % req.name)

def server():
    rospy.init_node( 'greeting_server')
    rospy.Service( 'greetings', Greeting, handleFunction)   # service name
    rospy.loginfo( 'Ready to handle the request')
    rospy.spin()

if __name__ == '__main__':
    server()
