cmake_minimum_required(VERSION 3.17)
project(Menu)

set(CMAKE_CXX_STANDARD 20)

set(RES CMenuItem/CMenuItem.h CMenuItem/CMenuItem.cpp
        CMenu/CMenu.h CMenu/CMenu.cpp)

add_library(${PROJECT_NAME} ${RES})
