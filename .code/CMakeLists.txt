cmake_minimum_required(VERSION 3.28)
project(_code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(_code
        aes.cpp
        aes.h
        main.cpp)
