cmake_minimum_required (VERSION 3.8)

project ("test_tasks")

set (CMAKE_CXX_STANDARD 20)

set (PROJECT_SOURCES
        test_tasks.cpp
        Curves.h
)

add_executable (test_tasks "test_tasks.cpp")
