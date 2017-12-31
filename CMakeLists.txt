cmake_minimum_required(VERSION 3.6)
project(MarsServer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenCV REQUIRED)

# Add OpenCV headers location to your include paths
include_directories(${OpenCV_INCLUDE_DIRS})

# Link your application with OpenCV libraries
link_libraries(${OpenCV_LIBS})

set(SOURCE_FILES main.cpp MarsServer.cpp MarsServer.h)
add_executable(MarsServer ${SOURCE_FILES})