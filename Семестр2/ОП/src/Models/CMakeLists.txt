cmake_minimum_required(VERSION 3.17)
project(Models)

set(CMAKE_CXX_STANDARD 20)

set(RES DataBase.cpp DataBase.h
        HotelRoom.cpp HotelRoom.h
        )

add_library(${PROJECT_NAME} ${RES})
