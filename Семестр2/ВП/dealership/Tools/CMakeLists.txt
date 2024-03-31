cmake_minimum_required(VERSION 3.17)
project(Tools)

set(CMAKE_CXX_STANDARD 20)

set(RES Tools.cpp Tools.h)

add_library(${PROJECT_NAME} ${RES})
