cmake_minimum_required(VERSION 3.24)
project(AppleFrameworksCpp DESCRIPTION "Apple Platform Framework C++ bindings")

set(CMAKE_CXX_STANDARD 23)

add_library(${PROJECT_NAME} STATIC
        "AppleFrameworks.hpp"
        "AppleFrameworks.cpp")
set_target_properties(${PROJECT_NAME} PROPERTIES
        PUBLIC_HEADER "AppleFrameworks.hpp"
)
target_include_directories(${PROJECT_NAME} PUBLIC .)
target_compile_definitions(${PROJECT_NAME} PRIVATE -DAPPLE_FRAMEWORKS_CPP_INSIDE)