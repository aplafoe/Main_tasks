cmake_minimum_required (VERSION 3.24)

project (CADEX_TASK)

set (CMAKE_CXX_STANDARD 20)

set (PROJECT_SOURCES
    main.cpp
    Curves.h
)

add_executable (CADEX_TASK ${PROJECT_SOURCES})
