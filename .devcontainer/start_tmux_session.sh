#!/bin/sh
# Name of the tmux session
SESSION="ros2"

# Start a new session with the session name
tmux new-session -d -s $SESSION

# Name the first window
tmux rename-window -t 0 'Main'

# Run a command in the first window. 'C-m' simulates the Enter key.
#tmux send-keys -t 'Main' 'top' C-m

# Create a new window with name and run a command
tmux new-window -t $SESSION:1 -n 'Mosquitto'
tmux send-keys -t 'Mosquitto' 'mosquitto -c /etc/mosquitto/conf.d/mosquitto.conf' C-m

# Create another window and run a command
tmux new-window -t $SESSION:2 -n 'Shell'
tmux send-keys -t 'Shell' 'echo "This is a shell"' C-m

# Attach to the session
tmux attach-session -t $SESSION
