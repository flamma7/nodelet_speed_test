cmake_minimum_required(VERSION 2.8.3)
project(nodelet_speed_test)

set(OpenCV_DIR /usr/share/OpenCV)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  nodelet
  roscpp
  sensor_msgs
  OpenCV
  cv_bridge
  image_transport
  std_msgs
)

catkin_package(
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS roscpp nodelet
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(pubber src/reg_pubber.cpp)
target_link_libraries(pubber ${catkin_LIBRARIES} ${OpenCV_LIBS})

add_executable(subber src/reg_subber.cpp)
target_link_libraries(subber ${catkin_LIBRARIES})

add_library(nodelet_speed_test
  src/NodeletPubber.cpp
  src/NodeletSubber.cpp
)
target_link_libraries(nodelet_speed_test ${catkin_LIBRARIES})
if(catkin_EXPORTED_LIBRARIES)
  add_dependencies(nodelet_speed_test ${catkin_EXPORTED_LIBRARIES})
endif()
