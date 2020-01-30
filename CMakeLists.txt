cmake_minimum_required (VERSION 3.0) 

set (PROJECT pacman)

project (${PROJECT})
 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -std=c++1y -pthread")
 
 

file (GLOB CPP_HEADERS "*.h")
file (GLOB CPP_SOURCES "*.cpp")
 
add_executable (${PROJECT} ${CPP_SOURCES} ${CPP_HEADERS})