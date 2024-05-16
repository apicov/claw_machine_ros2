import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import paho.mqtt.client as mqtt

class ROS2MQTTBridge(Node):
    def __init__(self):
        super().__init__('ros2_mqtt_bridge')
        #publishes movement comands (x,y for xcarve) of joystick or other controllers
        self.horizontal_mov_publisher = self.create_publisher(String, 'arrow_key', 1)
        #publishes commands for the claw controller (needs mqtt bridge)
        self.claw_cmds_publisher = self.create_publisher(String, 'claw_ctl', 1)

        # subscriber for claw control commands 
        self.claw_cmds_subscription = self.create_subscription(
            String,
            'claw_ctl',
            self.claw_cmds_callback,
            1)
        self.claw_cmds_subscription  # prevent unused variable warning
        
        self.mqtt_client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
        self.mqtt_client.on_connect = self.on_connect
        self.mqtt_client.on_message = self.on_message
        self.mqtt_client.connect("localhost", 1883, 60)
        self.mqtt_client.loop_start()

    def on_connect(self, client, userdata, flags, reason_code, properties):
        self.get_logger().info("Connected to MQTT Broker with result code " + str(reason_code))
        self.mqtt_client.subscribe("xcarve_ctl/joystick/cmd") # Subscribe to the MQTT topic

    def on_message(self, client, userdata, msg):
        topic = msg.topic

        if topic == "xcarve_ctl/joystick/cmd":
            self.get_logger().info('Received message from MQTT: "%s"' % msg.payload.decode())
            ros_msg = String()
            ros_msg.data = str(msg.payload.decode())
            
            if ros_msg.data == 'Button.red':
                #when it is a "red button pressed" cmd, it has to be handled by the claw ctl topic
                claw_msg = String()
                claw_msg.data = 'grab_seq'
                self.claw_cmds_publisher.publish(claw_msg)
            else:
                self.horizontal_mov_publisher.publish(ros_msg)

    def claw_cmds_callback(self, msg):
        #get ros 2 claw command and resend it as mqtt topic
        print('claw message',msg.data)
        self.mqtt_client.publish('claw_ctl/cmd', msg.data)


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