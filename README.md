# ROSALAN
This project is for testing [ALAN](https://arxiv.org/abs/1710.04296) on turtlebots in ROS.

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

You may get an error: `Unknown CMake command "generate_messages"` in the collvoid experimental directory. As a work around, you can delete the experimental folder completely.

You can now run the simulations:
```
$ roslaunch orca_nav deadlock.launch
```
or
```
$ roslaunch orca_nav congested.launch
```
or 
```
$ roslaunch orca_nav blank.launch
```
Sometimes the controller window crashes, just restart the simulation.
Sometimes only some of the robots move, just restart the simulation.


# The Code
Below is a few of the places of interrest if you wish to modify/experiement with ALAN:
All the used simulations are located in the `orca_nav` package. These are slight modifications of those found in the `multi_robot_stage`. Feel free to change these.

The actual ALAN code can be found in `collvoid/collvoid_local_planner/src`. In `collvoid_local_planner.cpp` is where we call the ALAN/ORCA calcuations. Specifically line 660.
The `ROSAgent.cpp` file is where the majority of the code is. Of interest are the methods: initAsMe, computeNewVelocity(specifically line 234 - 284), Boltzmann, addNextTimeStep and computeActionAverages.

There should be sufficent comments for those parts in the code, but prior knowlegde to the ALAN algorithm is assumed.

Some of the properties used are defined in the header files `ROSAgent.h` and `Agent.h`.
