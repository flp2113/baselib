cmake_minimum_required(VERSION 3.27)
project(baselib C)

set(CMAKE_C_STANDARD 23)

add_executable(baselib source/main.c
        source/ds.h
        source/baselib.h
        source/defs.h
        source/test.h)
