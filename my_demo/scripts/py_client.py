#!/usr/bin/env python3
import rospy
from my_demo.srv import *

def client():
    rospy.init_node( 'greeting_client')
    rospy.wait_for_service( 'greetings')
    try:
        greetings_client = rospy.ServiceProxy( 'greetings', Greeting)   # service name
        re = greetings_client( 'HAN', 20)
        rospy.loginfo( 'Message From Server: %s' % re.feedback)
    except rospy.ServiceException as e:
        rospy.logwarn( 'Service call failed: %s' % e)

if __name__ == '__main__':
    client()
