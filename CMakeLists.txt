cmake_minimum_required(VERSION 3.12)
project(algorithm_road)
set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -v)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/dist)


### Dependencies
# Boost
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "/home/jover/Workspace/packages/cpp/boost/1_78_0")
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "/home/jover/Workspace/packages/cpp/boost/1_78_0/stage/lib")
find_package(Boost 1.78.0)
include_directories(${Boost_INCLUDE_DIRS})

### Build
include_directories(./src)
add_subdirectory(./src)
