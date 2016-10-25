#! /bin/bash

sudo sh -c 'echo 255 > /sys/kernel/debug/tegra_fan/target_pwm'
source ~/catkin_ws/devel/setup.bash
roscore &
sleep 5
roslaunch automotive_server visual.launch &
rqt
