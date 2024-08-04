set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "/usr/local/bin/g++-14")

cmake_minimum_required(VERSION 3.10)
project(SourceLocationFormatter)

include_directories(include)

add_executable(main src/main.cpp)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

# Link GoogleTest to the test target
enable_testing()
add_executable(test_source_location_formatter tests/test_source_location_formatter.cpp)
target_link_libraries(test_source_location_formatter gtest gtest_main gmock gmock_main)

add_test(NAME test_source_location_formatter COMMAND test_source_location_formatter)
