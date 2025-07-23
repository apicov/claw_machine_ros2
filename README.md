# Claw Machine ROS2 Project

## Overview

This project provides a ROS2-based control system for a claw machine, integrating hardware control, keyboard input, and MQTT communication. It is designed for modularity and extensibility, leveraging ROS2 nodes and custom messages to manage the machine's movements and interactions.

## Project Structure

```
claw_machine_ros2/
├── src/
│   ├── claw_machine_msgs/         # Custom ROS2 messages (Position.msg)
│   └── keyboard_claw_controller/  # Main control package (nodes, scripts)
├── install/                       # ROS2 build/install artifacts
├── log/                           # Build and runtime logs
├── build/                         # Build artifacts
├── cache/                         # Build cache
├── README.md                      # Project documentation (this file)
└── ...
```

## Main Components

### 1. `keyboard_claw_controller` (ROS2 Python Package)
- **Nodes:**
  - `keyboard_publisher`: Publishes arrow key presses as ROS2 messages using `pynput`.
  - `xcarve_controller`: Controls the X-Carve CNC machine via serial commands, subscribing to joystick commands and publishing position.
  - `ros2_mqtt_bridge`: Bridges ROS2 topics and MQTT topics for remote control and status updates.
  - `basic_game`: Implements a simple game loop for the claw machine, orchestrating joystick enable/disable, movement, and grabbing.
- **Library:**
  - `claw_lib.py`: Provides a high-level Python interface for controlling the claw machine using ROS2 topics and services.

### 2. `claw_machine_msgs` (ROS2 Message Package)
- **Custom Message:**
  - `Position.msg`: Defines a position message with fields:
    - `std_msgs/Header header`
    - `float32 x`
    - `float32 y`
    - `float32 z`
    - `float32 speed`

## Setup & Build

### Prerequisites
- ROS2 (tested with Humble)
- Python 3.8+
- [pynput](https://pypi.org/project/pynput/) (for keyboard input)
- [pyserial](https://pypi.org/project/pyserial/) (for serial communication)
- [paho-mqtt](https://pypi.org/project/paho-mqtt/) (for MQTT bridge)

### Building the Workspace

1. **Clone the repository:**
   ```bash
   git clone <this-repo-url>
   cd claw_machine_ros2
   ```
2. **Install dependencies:**
   ```bash
   sudo apt update
   sudo apt install python3-colcon-common-extensions python3-pip
   pip3 install pynput pyserial paho-mqtt
   # Install ROS2 dependencies (if not already installed)
   rosdep install --from-paths src --ignore-src -r -y
   ```
3. **Build the workspace:**
   ```bash
   colcon build
   source install/setup.bash
   ```

## Usage

### Running the Nodes

1. **Keyboard Publisher:**
   Publishes arrow key presses to the `arrow_key` topic.
   ```bash
   ros2 run keyboard_claw_controller keyboard_publisher
   ```
2. **X-Carve Controller:**
   Controls the X-Carve CNC machine via serial.
   ```bash
   ros2 run keyboard_claw_controller xcarve_controller
   ```
3. **ROS2-MQTT Bridge:**
   Bridges ROS2 topics and MQTT topics.
   ```bash
   ros2 run keyboard_claw_controller ros2_mqtt_bridge
   ```
4. **Basic Game Loop:**
   Runs the main game logic for the claw machine.
   ```bash
   ros2 run keyboard_claw_controller basic_game
   ```

### Custom Message Example

The `Position` message is used for communicating positions to and from the X-Carve:
```msg
std_msgs/Header header
float32 x
float32 y
float32 z
float32 speed
```

## Configuration

- **X-Carve GRBL Settings:**
  See `src/xcarve_grbl_configuration.txt` for recommended GRBL configuration parameters for the X-Carve CNC machine.

## License

*TODO: Add license information here.*

## Maintainer
- rosdev (<a.pico@posteo.de>)
