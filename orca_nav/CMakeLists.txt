cmake_minimum_required(VERSION 2.8.3)
project(orca_nav)

find_package(catkin REQUIRED COMPONENTS geometry_msgs move_base_msgs actionlib move_base_msgs roscpp tf)

catkin_package()

catkin_add_env_hooks(SHELLS sh DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/env-hooks)

# Build the executable

add_executable(test2 src/test2.cpp)

target_link_libraries(test2 ${catkin_LIBRARIES})

add_executable(send_goal2 src/send_goal2.cpp)

target_link_libraries(send_goal2 ${catkin_LIBRARIES})

add_executable(simple_navigation_goals src/simple_navigation_goals.cpp)
if(catkin_EXPORTED_TARGETS)
  add_dependencies(simple_navigation_goals ${catkin_EXPORTED_TARGETS})
endif()
target_link_libraries(simple_navigation_goals ${catkin_LIBRARIES})


install(TARGETS simple_navigation_goals
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(DIRECTORY launch 
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

install(DIRECTORY maps 
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

install(DIRECTORY rviz 
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)


