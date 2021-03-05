cmake_minimum_required(VERSION 3.10)

# set the project name
project(2_2)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# bring the headers into the project
include_directories(../include)

file(GLOB SOURCES "*.cpp")

# add the executable
add_executable(2_2 ${SOURCES})