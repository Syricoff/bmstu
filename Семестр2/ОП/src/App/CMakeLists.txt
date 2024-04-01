cmake_minimum_required(VERSION 3.17)
project(App)

set(CMAKE_CXX_STANDARD 20)

set(res App.h App.cpp)

include_directories(../Menu)

include_directories(../Models)

include_directories(../Tools)

add_library(${PROJECT_NAME} ${res})

target_link_libraries(${PROJECT_NAME} Menu Models Tools)
