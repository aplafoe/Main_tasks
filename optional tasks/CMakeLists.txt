cmake_minimum_required (VERSION 3.24)

project (78_SOLUTION)

set (CMAKE_CXX_STANDARD 20)

set (PROJECT_SOURCES
    main.cpp
)

find_package(OpenMP REQUIRED)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/CurvesAPI)

add_executable (CADEX_TASK ${PROJECT_SOURCES})

target_link_libraries(CADEX_TASK Curves)
