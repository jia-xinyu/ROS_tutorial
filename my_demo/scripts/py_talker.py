#!/usr/bin/env python3
import rospy
from my_demo.msg import gps

def talker():
    rospy.init_node( 'pytalker', anonymous=True)
    x = 1.0
    y = 2.0
    state = 'working'
    pub = rospy.Publisher( 'gps_info', gps, queue_size=10)  # topic name

    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        rospy.loginfo( 'Talker: GPS: x = %f, y = %f')
        pub.publish(gps(state, x, y))
        x = 1.03 * x
        y = 1.01 * y
        rate.sleep()

if __name__ == '__main__':
    talker()
