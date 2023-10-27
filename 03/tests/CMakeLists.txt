cmake_minimum_required(VERSION 3.14)
project(Google_tests)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
# )

# 'Google_test' is the subproject name
# gtest_discover_tests(tests)

# 'lib' is the folder with Google Test sources
# add_subdirectory(lib)
# include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run test1.cpp test2.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)
