cmake_minimum_required(VERSION 3.17)
project(Dealership)

set(CMAKE_CXX_STANDARD 20)

include_directories(Models)
include_directories(Menu)
include_directories(Tools)
include_directories(Storage)
include_directories(MyVector)

add_subdirectory(Models)
add_subdirectory(Menu)
add_subdirectory(Tools)
add_subdirectory(Storage)
add_subdirectory(MyVector)


add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(Dealership Models Menu Tools Storage)