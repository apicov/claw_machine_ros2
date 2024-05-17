import rclpy
from rclpy.node import Node
from std_msgs.msg import UInt8

class GameCtl(Node):
    def __init__(self):
        super().__init__('basic_game')
        self.joystick_enable_publisher = self.create_publisher(UInt8, 'joystick_enable', 1)
        self.last_key = None
        self.timer = self.create_timer(10, self.timer_callback)

        self.prev_joystick_status = 0
        
    def timer_callback(self):
        msg = UInt8()
        msg.data = 1 if self.prev_joystick_status == 0 else 0
        self.prev_joystick_status = msg.data

        self.joystick_enable_publisher.publish(msg)
        self.get_logger().info(f'Publishing: "{msg.data}"')

def main(args=None):
    rclpy.init(args=args)
    ctl = GameCtl()
    rclpy.spin(ctl)
    ctl.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()