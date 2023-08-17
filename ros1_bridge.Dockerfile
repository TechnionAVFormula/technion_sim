
FROM ubuntu:bionic
# Set ARGs for ROS distros with default values
ARG ROS1_DISTRO=melodic
ARG ROS2_DISTRO=dashing


RUN DEBIAN_FRONTEND=noninteractive apt-get update -y &&\
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
      python3-setuptools \
      locales \
      wget

RUN locale &&\
apt update &&  apt install locales &&\
locale-gen en_US en_US.UTF-8 &&\
update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8 &&\
export LANG=en_US.UTF-8 &&\
locale  # verify settings

ENV LANG=en_US.UTF-8

# Set up ROS 2 keys
RUN  apt update && apt install -y curl gnupg2 lsb-release &&\
     curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key  -o /usr/share/keyrings/ros-archive-keyring.gpg

RUN echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" |  tee /etc/apt/sources.list.d/ros2.list > /dev/null

# Install development packages and ROS 2 Dashing
RUN DEBIAN_FRONTEND=noninteractive apt update && DEBIAN_FRONTEND=noninteractive apt install -y \
  build-essential \
  cmake \
  git \
  python3-colcon-common-extensions \
  python3-pip \
  python-rosdep \
  python3-vcstool \
  wget &&\
  python3 -m pip install -U \
  argcomplete \
  flake8 \
  flake8-blind-except \
  flake8-builtins \
  flake8-class-newline \
  flake8-comprehensions \
  flake8-deprecated \
  flake8-docstrings \
  flake8-import-order \
  flake8-quotes \
  pytest-repeat \
  pytest-rerunfailures \
  pytest \
  pytest-cov \
  pytest-runner \
  setuptools
# install Fast-RTPS dependencies
RUN apt install --no-install-recommends -y \
  libasio-dev \
  libtinyxml2-dev
# install Cyclone DDS dependencies
RUN apt install --no-install-recommends -y \
  libcunit1-dev

# ########## Add additional ROS 2 packages here ##########
# e.g., 
# RUN apt-get install -y ros-${ROS2_DISTRO}-some-package

# Bootstrap rosdep
RUN rosdep init


# Install lsb-release (if not already present)
RUN apt-get update && apt-get install -y lsb-release

# Add the ROS public key
RUN apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key F42ED6FBAB17C654

# Set up the ROS 1 repository
RUN echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -cs) main" > /etc/apt/sources.list.d/ros1-latest.list

# Update the package list
RUN apt-get update

# Install ROS 1 Melodic
RUN apt-get update && apt-get install -y \
    ros-${ROS1_DISTRO}-desktop-full

# ########## Add additional ROS 1 packages here ##########
RUN apt-get install -y ros-${ROS1_DISTRO}-geometry-msgs \
                        ros-${ROS1_DISTRO}-sensor-msgs \
                        ros-${ROS1_DISTRO}-ackermann-msgs \
                        ros-${ROS1_DISTRO}-catkin \
                        ros-${ROS1_DISTRO}-roscpp \
                        ros-${ROS1_DISTRO}-roslaunch \
                        ros-${ROS1_DISTRO}-rosmsg \
                        ros-${ROS1_DISTRO}-std-msgs



RUN mkdir -p /ros2_${ROS2_DISTRO}/src
WORKDIR /ros2_${ROS2_DISTRO}
RUN wget https://raw.githubusercontent.com/ros2/ros2/${ROS2_DISTRO}/ros2.repos
RUN vcs import src < ros2.repos
RUN if [ ! -f /etc/ros/rosdep/sources.list.d/20-default.list ]; then rosdep init; fi && \
    rosdep update && \
    rosdep install --from-paths src --ignore-src --rosdistro dashing -y --skip-keys "console_bridge fastcdr fastrtps libopensplice67 libopensplice69 rti-connext-dds-5.3.1 urdfdom_headers"

RUN colcon build --symlink-install

# RUN apt-get install -y python-roslaunch





RUN mkdir -p /ros1_bridge/src
WORKDIR /ros1_bridge
RUN git clone https://github.com/ros2/ros1_bridge
RUN /bin/bash -c ". /ros2_${ROS2_DISTRO}/install/local_setup.bash &&\
                  colcon build --symlink-install --packages-select ros1_bridge --cmake-force-configure"

WORKDIR /

# ########## Add Volumes for local packages ##########
# VOLUME ["/ros1_ws", "/ros2_ws"]

ENV ROS1_DISTRO=$ROS1_DISTRO
ENV ROS2_DISTRO=$ROS2_DISTRO

COPY ros_entrypoint.sh /
ENTRYPOINT ["/ros_entrypoint.sh"]
CMD ["bash"]
