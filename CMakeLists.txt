cmake_minimum_required(VERSION 3.17)
project(InfotecsAc)

set(CMAKE_CXX_STANDARD 14)

add_executable(InfotecsAc main.cpp
        quickSort.hpp
        globalVar.hpp)

add_subdirectory(BOOST_TEST)
