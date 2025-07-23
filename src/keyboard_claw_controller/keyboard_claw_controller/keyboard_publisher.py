"""Publishes arrow key presses as ROS2 messages using pynput and rclpy."""
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from pynput import keyboard

class ArrowKeyPublisher(Node):
    """ROS2 node that publishes arrow key presses to a ROS2 topic."""
    def __init__(self):
        """Initialize the ArrowKeyPublisher node and set up the keyboard listener."""
        super().__init__('keyboard_publisher')
        self.publisher_ = self.create_publisher(String, 'arrow_key', 1)
        self.last_key = None
        self.timer = self.create_timer(0.1, self.timer_callback)
        listener = keyboard.Listener(on_press=self.on_press, on_release=self.on_release)
        listener.start()

    def on_press(self, key):
        """Handle key press events and update the last key pressed."""
        if key in [keyboard.Key.up, keyboard.Key.down, keyboard.Key.left, keyboard.Key.right]:
            self.last_key = key

    def on_release(self, key):
        """Handle key release events and reset the last key if released."""
        if key == self.last_key:
            self.last_key = None

    def timer_callback(self):
        """Publish the last key pressed as a ROS2 message at regular intervals."""
        if self.last_key:
            msg = String()
            msg.data = f'{self.last_key}'
            self.publisher_.publish(msg)
            self.get_logger().info(f'Publishing: "{msg.data}"')

def main(args=None):
    """Entry point for running the ArrowKeyPublisher node."""
    rclpy.init(args=args)
    arrow_key_publisher = ArrowKeyPublisher()
    rclpy.spin(arrow_key_publisher)
    arrow_key_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()