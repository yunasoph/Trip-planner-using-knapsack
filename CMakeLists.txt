cmake_minimum_required(VERSION 3.10)
project(TripPlanner)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell the program where to find the data folder
add_definitions(-DDATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}/data/")

# Add your source files
add_executable(TripPlanner src/main.cpp src/TripPlanner.cpp)
