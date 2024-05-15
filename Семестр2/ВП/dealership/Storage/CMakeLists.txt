cmake_minimum_required(VERSION 3.17)
project(Storage)

set(CMAKE_CXX_STANDARD 20)

set(RES Storage.cpp Storage.h)

include_directories(../Models)


add_library(${PROJECT_NAME} ${RES})
target_link_libraries(Storage Models)
