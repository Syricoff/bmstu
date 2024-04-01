cmake_minimum_required(VERSION 3.17)
project(OP)

set(CMAKE_CXX_STANDARD 20)

include_directories(Models)
include_directories(Menu)
include_directories(App)
include_directories(Tools)


add_subdirectory(Models)
add_subdirectory(Menu)
add_subdirectory(App)
add_subdirectory(Tools)



add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(OP App)