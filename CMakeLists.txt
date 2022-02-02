cmake_minimum_required(VERSION 3.9)
project(proc_planner)
set(CMAKE_VERBOSE_MAKEFILE ON)

## Make top-level project name available in all nested projects.
set(MW_TOP_LEVEL_PROJECT_NAME ${PROJECT_NAME})
set(PROJECT_SRC_FILES "src")


## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
roscpp
sonia_common
std_msgs
trajectory_msgs
)

add_definitions(
-D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DROS_PROJECT -DMW_SCHED_OTHER -DSTACK_SIZE=200000 )

## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
   CATKIN_DEPENDS roscpp sonia_common std_msgs trajectory_msgs 
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  include
  ${PROJECT_SOURCE_DIR}
  ${Boost_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
)

## Get list of .c files in project source directory
file(GLOB ${PROJECT_NAME}_C_SOURCES RELATIVE ${PROJECT_SOURCE_DIR} ${PROJECT_SRC_FILES}/*.c)
## Get list of .cpp files in project source directory
file(GLOB ${PROJECT_NAME}_CPP_SOURCES RELATIVE ${PROJECT_SOURCE_DIR} ${PROJECT_SRC_FILES}/*.cpp)

## Declare executable
add_executable(${PROJECT_NAME}
   ${PROJECT_SRC_FILES}/proc_planner.cpp
   ${${PROJECT_NAME}_C_SOURCES}
   ${${PROJECT_NAME}_CPP_SOURCES}
)

## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
target_link_libraries(${PROJECT_NAME}
   ${catkin_LIBRARIES}
   ${Boost_LIBRARIES}
   rt
   ${CMAKE_DL_LIBS}
)

SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -fpermissive" )
SET( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -include stdbool.h" )
foreach(file_i ${CUDA_BINS})
add_custom_command(TARGET ${PROJECT_NAME}
POST_BUILD
COMMAND ${CMAKE_COMMAND}
ARGS -E copy ${PROJECT_SOURCE_DIR}/${file_i} ${CATKIN_DEVEL_PREFIX}/untitled_ert_rtw/${file_i})
endforeach( file_i )