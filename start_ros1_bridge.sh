#!/bin/bash

# Source ROS1 Melodic (change this if you're using a different ROS1 distro)
source /opt/ros/melodic/setup.bash

# Start roscore for ROS1
roscore &

# Give roscore some time to start
sleep 5
python3 ackermann_listener.py
# Get the IP address of the host machine (replace with your interface name if not 'eth0')
HOST_IP=$(hostname -I | awk '{print $1}')

# Set ROS_MASTER_URI for ROS1
export ROS_MASTER_URI=http://$HOST_IP:11311/

# Start the docker containers (ros1_bridge and eufs_sim)
# Make sure that the bridge uses the above ROS_MASTER_URI
docker-compose up --build

docker-compose down

# Once done, kill roscore
killall roscore
