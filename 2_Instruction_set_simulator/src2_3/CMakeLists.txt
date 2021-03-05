cmake_minimum_required(VERSION 3.10)

# set the project name
project(2_3)

# bring the headers into the project
include_directories(../include)

file(GLOB SOURCES "*.cpp")

# add the executable
add_executable(2_3 ${SOURCES})
