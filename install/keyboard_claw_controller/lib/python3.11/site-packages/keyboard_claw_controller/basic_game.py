import rclpy
from rclpy.node import Node
from std_msgs.msg import UInt8
from claw_machine_msgs.msg import Position

class GameCtl(Node):
    def __init__(self):
        super().__init__('basic_game')
        self.joystick_enable_publisher = self.create_publisher(UInt8, 'joystick_enable', 1)
        self.xcarve_goto_publisher = self.create_publisher(Position, 'xcarve_goto', 1)
        self.last_key = None
        self.timer = self.create_timer(5, self.timer_callback)

        self.prev_joystick_status = 0
        
    def timer_callback(self):
        #msg = UInt8()
        #msg.data = 1 if self.prev_joystick_status == 0 else 0
        #self.prev_joystick_status = msg.data

        #self.joystick_enable_publisher.publish(msg)

        msg = Position()
        msg.x = 400.0
        msg.y = 300.0
        self.xcarve_goto_publisher.publish(msg)

        self.get_logger().info(f'Publishing: "{msg}"')

def main(args=None):
    rclpy.init(args=args)
    ctl = GameCtl()
    rclpy.spin(ctl)
    ctl.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()