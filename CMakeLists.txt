cmake_minimum_required(VERSION 3.7)
project(sockets)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(sockets ${SOURCE_FILES})