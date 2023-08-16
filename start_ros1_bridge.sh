#!/bin/bash

# Source ROS1 Melodic (change this if you're using a different ROS1 distro)
source /opt/ros/melodic/setup.bash

# Start roscore for ROS1
roscore &

# Give roscore some time to start
sleep 5

# Set ROS_MASTER_URI for ROS1
export ROS_MASTER_URI=http://localhost:11311/

# Start the docker containers (ros1_bridge and eufs_sim)
docker-compose up --build

# Once done, kill roscore
killall roscore
