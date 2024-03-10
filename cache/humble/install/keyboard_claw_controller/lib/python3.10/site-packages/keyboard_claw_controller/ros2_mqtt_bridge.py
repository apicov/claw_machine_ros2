import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import paho.mqtt.client as mqtt

class ROS2MQTTBridge(Node):
    def __init__(self):
        super().__init__('ros2_mqtt_bridge')
        self.publisher_ = self.create_publisher(String, 'arrow_key', 1)
        
        self.mqtt_client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
        self.mqtt_client.on_connect = self.on_connect
        self.mqtt_client.on_message = self.on_message
        self.mqtt_client.connect("localhost", 1883, 60)
        self.mqtt_client.loop_forever()

    def on_connect(self, client, userdata, flags, reason_code, properties):
        self.get_logger().info("Connected to MQTT Broker with result code " + str(reason_code))
        self.mqtt_client.subscribe("xcarve_ctl/joystick/cmd") # Subscribe to the MQTT topic

    def on_message(self, client, userdata, msg):
        self.get_logger().info('Received message from MQTT: "%s"' % msg.payload.decode())
        ros_msg = String()
        ros_msg.data = msg.payload.decode()
        self.publisher_.publish(ros_msg) # Publish to the ROS 2 topic

def main(args=None):
    rclpy.init(args=args)

    ros2_mqtt_bridge = ROS2MQTTBridge()

    rclpy.spin(ros2_mqtt_bridge)

    # Cleanup
    ros2_mqtt_bridge.mqtt_client.loop_stop()
    ros2_mqtt_bridge.mqtt_client.disconnect()
    ros2_mqtt_bridge.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()