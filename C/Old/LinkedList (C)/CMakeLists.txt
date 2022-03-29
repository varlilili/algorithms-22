cmake_minimum_required(VERSION 3.21)
project(LinkedList__C_ C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(LinkedList__C_
        linkedlist.c
        linkedlist.h test.c)
