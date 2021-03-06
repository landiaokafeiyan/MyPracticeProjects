cmake_minimum_required(VERSION 2.8.3)
project(optObjUAV)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  geometry_msgs
  image_transport
  #opencv2
  roscpp
  rospy
  sensor_msgs
  std_msgs
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)
find_package(OpenCV REQUIRED core ocl)

message(STATUS "Found OpenCV: ${OpenCV_LIBS}" )


## find aruco lib
file(GLOB MY_aruco_LIB_SOURCES src/aruco_lib/*.cpp)
include_directories("${PROJECT_SOURCE_DIR}/src/aruco_lib")

## find KF lib
file(GLOB MY_KF_LIB_SOURCES src/KF_lib/*.cpp)
include_directories("${PROJECT_SOURCE_DIR}/src/KF_lib")

## find EKF lib
file(GLOB MY_EKF_LIB_SOURCES src/EKF_lib/*.cpp)
include_directories("${PROJECT_SOURCE_DIR}/src/EKF_lib")

## find Yu Yun math library
file(GLOB UAV_MATH_LIB_SOURCES src/math_lib/*.c)
include_directories("${PROJECT_SOURCE_DIR}/src/math_lib")
SET_SOURCE_FILES_PROPERTIES(${UAV_MATH_LIB_SOURCES} PROPERTIES LANGUAGE CXX)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend and a run_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependencies might have been
##     pulled in transitively but can be declared for certainty nonetheless:
##     * add a build_depend tag for "message_generation"
##     * add a run_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
add_message_files(
  FILES
  trackInfo.msg
#  arInfo.msg
#  trackerDebug.msg
)

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

generate_messages(
  DEPENDENCIES
  std_msgs
  geometry_msgs
)

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   std_msgs  # Or other packages containing msgs
# )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES optObjUAV
#  CATKIN_DEPENDS roscpp rospy
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
${catkin_INCLUDE_DIRS}
${OpenCV_INCLUDE_DIRS}
)

## Declare a cpp library
# add_library(optObjUAV
#   src/${PROJECT_NAME}/optObjUAV.cpp
# )

## Declare a cpp executable
# add_executable(optObjUAV_node src/optObjUAV_node.cpp)
#add_executable(optObjUAV_node src/optObjUAV.cpp) 
#target_link_libraries(optObjUAV_node ${catkin_LIBRARIES} ${OpenCV_LIBRARIES} )
#add_executable(test_color_node src/test_color.cpp) 
#target_link_libraries(test_color_node ${catkin_LIBRARIES} ${OpenCV_LIBRARIES} )

#add_executable(test_receive_node src/test_receive.cpp) 
#target_link_libraries(test_receive_node ${catkin_LIBRARIES} ${OpenCV_LIBRARIES} )

#add_executable(get_video_node src/image_to_video.cpp) 
#target_link_libraries(get_video_node ${catkin_LIBRARIES} ${OpenCV_LIBRARIES}  )

#add_executable(get_video_asi_node src/image_to_video_asi.cpp) 
#target_link_libraries(get_video_asi_node ${catkin_LIBRARIES} ${OpenCV_LIBRARIES}  )


# aruco
add_executable(optAruco1 src/aruco_test_on_ros.cpp ${MY_aruco_LIB_SOURCES}) 
target_link_libraries(optAruco1 ${catkin_LIBRARIES} ${OpenCV_LIBRARIES}  )

#add_executable(stable src/stable.cxx ${MY_aruco_LIB_SOURCES}) 
#target_link_libraries(stable ${catkin_LIBRARIES} ${OpenCV_LIBRARIES}  )

add_executable(optAruco2 src/aruco_test_on_ros2.cpp ${MY_aruco_LIB_SOURCES})
target_link_libraries(optAruco2 ${catkin_LIBRARIES} ${OpenCV_LIBRARIES}  )

#add_executable(optAruco src/optArucoTrack.cpp ${MY_aruco_LIB_SOURCES})
#target_link_libraries(optAruco ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

add_executable(optColor src/optColorTrack.cpp src/Object.cpp)
target_link_libraries(optColor ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
