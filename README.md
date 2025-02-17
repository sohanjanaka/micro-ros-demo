# Micro-ros-demo
Micro ROS Demonstration program

# Native Ubuntu Configuration

    # install ros2 hubmble
    https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html
    echo $ROS_DISTRO

    # install pip
    sudo apt-get install python3-pip
    pip3 list

    # install colcon
    sudo apt install python3-colcon-common-extensions

    # Source the ROS 2 installation
    echo $ROS_DISTRO
    source /opt/ros/$ROS_DISTRO/setup.bash

    # Create a workspace and download the micro-ROS tools
    mkdir microros_ws
    cd microros_ws
    git clone -b $ROS_DISTRO https://github.com/micro-ROS/micro_ros_setup.git src/micro_ros_setup

    # Update dependencies using rosdep
    sudo apt update && rosdep update
    rosdep install --from-paths src --ignore-src -y

    # Build micro-ROS tools and source them
    colcon build
    source install/local_setup.bash

    # run micro_ros_agent serial
    ros2 run micro_ros_agent micro_ros_agent serial --dev /dev/ttyUSB0
    # run micro_ros_agent udp / wifi
    ros2 run micro_ros_agent micro_ros_agent udp4 --port 8888


# docker approch

install docker engine (docker engine is recommended for serial communication)

microros over wifi
```bash
sudo docker run -it --rm -p 8888:8888/udp microros/micro-ros-agent:humble udp4 --port 8888
```

microros over serial
```bash  
sudo docker run -it --rm -v /dev/ttyUSB0:/dev/ttyUSB0 --privileged microros/micro-ros-agent:humble serial --dev /dev/ttyUSB0
```
