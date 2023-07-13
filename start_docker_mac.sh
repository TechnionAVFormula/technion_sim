#!/bin/bash

# Determine platform based on machine architecture
ARCH=$(uname -m)

if [ "$ARCH" = "aarch64" ]; then
    PLATFORM="linux/arm64"
else
    PLATFORM="linux/amd64"
fi

# Build and run Docker with platform determined above
docker build -t eufs_sim .
xhost + 
sudo docker run -it --rm -v ~/.Xauthority:/root/.Xauthority --platform $PLATFORM --privileged --net=host -e DISPLAY=$DISPLAY eufs_sim:latest ./start_simulator.sh
