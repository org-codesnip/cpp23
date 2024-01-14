cmake_minimum_required(VERSION 3.27)
project(cpp23)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

add_executable(
        cpp23

        graph/bfs.cpp
        graph/dijkstra.cpp
        graph/prim.cpp

        main.cpp
)
