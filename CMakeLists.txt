cmake_minimum_required(VERSION 3.3)
project(Algorithms)

set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${dir}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${dir}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${dir}/bin")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Algorithms ${SOURCE_FILES})

add_executable(p1000 src/oj/hangdian/p1000.cpp)
add_executable(p1001 src/oj/hangdian/p1001.cpp)

add_executable(LC_p0003 src/oj/leetcode/p0003.cpp)
add_executable(LC_p0004 src/oj/leetcode/p0004.cpp)
