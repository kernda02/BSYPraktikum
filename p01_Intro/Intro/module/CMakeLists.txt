cmake_minimum_required(VERSION 3.13)
project(module C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(module
        func1.c
        func1.h
        func2.c
        func2.h
        func3.c
        func3.h
        main.c
        main_m2.c
        main_m3.c
        mydefs.h)
