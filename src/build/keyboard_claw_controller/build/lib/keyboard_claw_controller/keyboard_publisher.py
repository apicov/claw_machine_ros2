import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from pynput import keyboard

class ArrowKeyPublisher(Node):
    def __init__(self):
        super().__init__('keyboard_publisher')
        self.publisher_ = self.create_publisher(String, 'arrow_key', 1)
        self.last_key = None
        self.timer = self.create_timer(0.1, self.timer_callback)
        listener = keyboard.Listener(on_press=self.on_press, on_release=self.on_release)
        listener.start()

    def on_press(self, key):
        if key in [keyboard.Key.up, keyboard.Key.down, keyboard.Key.left, keyboard.Key.right]:
            self.last_key = key

    def on_release(self, key):
        if key == self.last_key:
            self.last_key = None

    def timer_callback(self):
        if self.last_key:
            msg = String()
            msg.data = f'{self.last_key} pressed'
            self.publisher_.publish(msg)
            self.get_logger().info(f'Publishing: "{msg.data}"')

def main(args=None):
    rclpy.init(args=args)
    arrow_key_publisher = ArrowKeyPublisher()
    rclpy.spin(arrow_key_publisher)
    arrow_key_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()