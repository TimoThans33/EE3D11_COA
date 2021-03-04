cmake_minimum_required(VERSION 3.10)

# set the project name
project(instruction_set_simulator)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# bringt the headers into the project
include_directories(include)

file(GLOB SOURCES "src2_1/*.cpp")

# add the executable
add_executable(app ${SOURCES})