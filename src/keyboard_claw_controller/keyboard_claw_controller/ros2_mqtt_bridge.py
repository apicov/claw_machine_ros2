import rclpy
from rclpy.node import Node
from std_msgs.msg import String, UInt8
import paho.mqtt.client as mqtt

class ROS2MQTTBridge(Node):
    def __init__(self):
        super().__init__('ros2_mqtt_bridge')
        #publishes movement comands of joystick or other controllers
        self.joystick_publisher = self.create_publisher(String, 'joystick/cmd', 1)
        #publishes task done message from claw controller
        self.claw_status_publisher = self.create_publisher(String, 'claw/status', 1)

        # subscriber for claw control commands 
        self.claw_cmds_subscription = self.create_subscription(
            String,
            'claw/ctl',
            self.claw_cmds_callback,
            1)
        self.claw_cmds_subscription  # prevent unused variable warning

        # subscriber for enable/disable joystick message 
        self.joystick_enable_subscription = self.create_subscription(
            UInt8,
            'joystick/enable',
            self.joystick_enable_callback,
            1)
        self.joystick_enable_subscription  # prevent unused variable warning
        
        self.mqtt_client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
        self.mqtt_client.on_connect = self.on_connect
        self.mqtt_client.on_message = self.on_message
        self.mqtt_client.connect("localhost", 1883, 60)
        self.mqtt_client.loop_start()

    def on_connect(self, client, userdata, flags, reason_code, properties):
        self.get_logger().info("Connected to MQTT Broker with result code " + str(reason_code))
        self.mqtt_client.subscribe("joystick/cmd") # Subscribe to the MQTT topic
        self.mqtt_client.subscribe("claw/status") 

    # receives mqtt message
    def on_message(self, client, userdata, msg):
        topic = msg.topic

        self.get_logger().info('Received message from MQTT: "%s"' % msg.payload.decode())

        if topic == "joystick/cmd":
            ros_msg = String()
            ros_msg.data = str(msg.payload.decode())
            self.joystick_publisher.publish(ros_msg)
        
        elif topic == "claw/status":
            ros_msg = String()
            ros_msg.data = str(msg.payload.decode())
            self.claw_status_publisher.publish(ros_msg)
            #self.get_logger().info('llego el don')

            
            
    def claw_cmds_callback(self, msg):
        #get ros 2 claw command and resend it as mqtt topic
        print('claw message',msg.data)
        self.mqtt_client.publish('claw/ctl', msg.data)

    def joystick_enable_callback(self, msg):
        #get ros 2 joystick_enable message and resend it as mqtt topic
        print('jostick_enable message',msg.data)
        self.mqtt_client.publish('joystick/enable', msg.data)


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