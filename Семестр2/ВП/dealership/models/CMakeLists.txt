cmake_minimum_required(VERSION 3.17)
project(models)

set(CMAKE_CXX_STANDARD 20)

set(RES User/User.h User/User.cpp
        Car/Car.h Car/Car.cpp
        Client/Client.h Client/Client.cpp
        CMenuItem/CMenuItem.h CMenuItem/CMenuItem.cpp
        CMenu/CMenu.h CMenu/CMenu.cpp
        Employee/Employee.h Employee/Employee.cpp
        )

add_library(${PROJECT_NAME} ${RES})
