cmake_minimum_required(VERSION 3.12)
project(CO572_2018_Coursework1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CO572_2018_Coursework1
        Coursework1_2018.cpp
        Joins.cpp
        Joins.hpp
        Storage.cpp
        Storage.hpp
        Volcano.cpp
        Volcano.hpp)
