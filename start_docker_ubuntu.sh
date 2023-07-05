#!/bin/bash
docker build -t eufs_sim .
xhost +
sudo docker run -it --rm --net=host -e DISPLAY=$DISPLAY eufs_sim:latest