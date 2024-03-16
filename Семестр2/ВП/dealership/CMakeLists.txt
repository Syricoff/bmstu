cmake_minimum_required(VERSION 3.17)
project(Dealership)

set(CMAKE_CXX_STANDARD 20)

include_directories(models)

add_subdirectory(models)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(Dealership models)