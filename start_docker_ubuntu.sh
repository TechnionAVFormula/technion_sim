#!/bin/bash
xhost +
sudo docker run -it --rm --net=host -e DISPLAY=$DISPLAY eufs_sim:latest