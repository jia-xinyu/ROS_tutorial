#!/usr/bin/env python3
import rospy
import math
from my_demo.msg import gps

def gpsCallback(gps):
    distance = math.sqrt(math.pow(gps.x,2)+math.pow(gps.y,2))
    rospy.loginfo( "Listener: GPS distance = %f, state = %s", distance, gps.state)

def listener():
    rospy.init_node( 'pylistener')
    rospy.Subscriber( 'gps_info', gps, gpsCallback) # topic name

if __name__ == '__main__':
    listener()
