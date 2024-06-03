cmake_minimum_required(VERSION 3.17)
project(MyVector)

set(CMAKE_CXX_STANDARD 20)

set(RES MyVector.h MyVector.cpp)

add_library(${PROJECT_NAME} ${RES})