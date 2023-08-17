FROM osrf/ros:galactic-desktop

SHELL ["/bin/bash", "-c"]

ADD start_simulator.sh /

RUN apt-get update && \
    apt-get install -y \
    git \ 
    python3-pip \
    tmux \
    vim \
    nano && \
    pip3 install colcon-common-extensions -U && \
    apt-get install -y python3-tk && \
    apt-get install -y ros-galactic-gazebo-ros \
                       ros-galactic-gazebo-ros-pkgs \
                       ros-galactic-xacro \
                       ros-galactic-ackermann-msgs \
                       ros-galactic-joint-state-publisher-gui \
                       ros-galactic-tf-transformations && \
    apt-get upgrade -y ros-galactic-geometry-msgs

# Set environment variable directly without .bashrc
ENV EUFS_MASTER /eufs

# Clone git repositories
RUN mkdir -p /eufs/src && \
    cd /eufs/src && \
    git clone https://gitlab.com/eufs/eufs_sim.git && \
    git clone https://gitlab.com/eufs/eufs_msgs.git && \
    git clone https://gitlab.com/eufs/eufs_rviz_plugins.git

# Install ROS dependencies
RUN source /opt/ros/galactic/setup.bash && \
    cd /eufs && \
    rosdep update && \
    rosdep install --from-paths src --ignore-src -r -y

# Build the ROS packages (if necessary)
# RUN source /opt/ros/galactic/setup.bash && \
#     cd /eufs && \
#     colcon build

WORKDIR /
CMD ["bash", "./start_simulator.sh"]
