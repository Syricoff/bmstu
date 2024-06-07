cmake_minimum_required(VERSION 3.17)
project(exception)

set(CMAKE_CXX_STANDARD 20)

set(res Exception.h Exception.cpp)

add_library(${PROJECT_NAME} ${res})
