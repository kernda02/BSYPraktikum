cmake_minimum_required(VERSION 3.13)
project(listen C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(listen
        commondefs.h
        main.c
        mlist.c
        mlist.h
        mthread.c
        mthread.h
        test1.c
        test2.c
        test3.c
        test4.c)
