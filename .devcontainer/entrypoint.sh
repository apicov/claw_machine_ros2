#!/bin/bash

touch ~/cucu.txt

# Execute command 1
echo "ros entrypoint..."
/bin/sh /ros_entrypoint.sh

# Execute command 2
echo "mosquitto broker..."
/usr/sbin/mosquitto &



exec "$@"
