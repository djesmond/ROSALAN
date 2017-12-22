# ROSALAN
This project is for testing ALAN on turtlebots in ROS.

# Requirements
* Ubuntu 14 (Later versions may not be supported)
* ROS (Indigo tested)
* TurtleBot software (for ROS Indigo)

# Install
1. Install [Indigo](http://wiki.ros.org/indigo/Installation/Ubuntu)
2. Install [catkin tools](http://catkin-tools.readthedocs.io/en/latest/installing.html)
3. Install [Turtlebot ROS](http://wiki.ros.org/turtlebot/Tutorials/indigo/Turtlebot%20Installation)

# Note on VM's
This project uses stage and rviz for simulation. There are issues with this when running in a VM. Please disable 3D acceleration or the code will crash. Highly recommended to run this in native OS.

# Running
1. [Create a new workspace with caktin](http://wiki.ros.org/catkin/Tutorials/create_a_workspace)
2. Run the following commands from the workspace:
```
$ mkdir src && cd src
$ git clone https://github.com/djesmond/ROSALAN
$ cd ..
$ catkin_make
$ source devel/setup.sh
```
You can now run the simulations:
```
$ roslaunch orca_nav deadlock.launch
```
or
```
roslaunch orca_nav congested.launch
```
Doesn't always work, so try a few times

