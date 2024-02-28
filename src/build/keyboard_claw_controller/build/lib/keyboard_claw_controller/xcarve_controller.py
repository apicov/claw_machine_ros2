#!/usr/bin/env python
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import serial


class XcarveController(Node):
    def __init__(self):
        super.__init__('xcarve_controller')
        self.homing()

    def homing(self):
        self.serial_port.flushInput()
        #print('Going home')
        self.get_logger().info('Going home')
        output = self.send_cmd("$H")
        if output.find('ALARM', 0, len(output)) != -1:
            #print ('There was an alarm lock. Killing it')
            self.get_logger().info('There was an alarm lock. Killing it')
            #read and discard next four lines (part of error message)
            for i in range(4):
                self.serial_port.readline().decode('utf-8')
            self.send_cmd("$X")
        self.send_cmd("g91") # sending again relative positioning
        self.send_cmd("g21") # use millimiter units (g20 for inches)
        self.send_cmd("$10=14")
        self.get_logger.info('home position')

    def send_cmd(self,cmd):
        print(cmd)
        b_cmd = cmd+'\n'
        self.lock.acquire()
        self.serial_port.write(b_cmd.encode())
        grbl_out = self.serial_port.readline().decode('utf-8')
        self.lock.release()
        self.get_logger.info('send_cmd : ' + cmd + ": " + grbl_out.strip())
        return grbl_out


def main(args=None):
    rclpy.init(args=args)
    xcarve_controller = XcarveController()
    rclpy.spin(xcarve_controller)
    xcarve_controller.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()