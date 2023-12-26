cmake_minimum_required(VERSION 3.24)
project(AppleFrameworksCpp DESCRIPTION "Apple Platform Framework C++ bindings")

set(CMAKE_CXX_STANDARD 23)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

file(GLOB_RECURSE METAL_FRAMEWORK_HEADERS
        Metal/*.hpp
)
file(GLOB_RECURSE FOUNDATION_FRAMEWORK_HEADERS
        Foundation/*.hpp
)
file(GLOB_RECURSE METALKIT_FRAMEWORK_HEADERS
        MetalKit/*.hpp
)
file(GLOB_RECURSE METALFX_FRAMEWORK_HEADERS
        MetalFX/*.hpp
)
file(GLOB_RECURSE QUARTZCORE_FRAMEWORK_HEADERS
        QuartzCore/*.hpp
)
file(GLOB_RECURSE APPKIT_FRAMEWORK_HEADERS
        AppKit/*.hpp
)

set(APPLE_FRAMEWORK_HEADERS
        ${METAL_FRAMEWORK_HEADERS}
        ${METALKIT_FRAMEWORK_HEADERS}
        ${FOUNDATION_FRAMEWORK_HEADERS}
        ${METALFX_FRAMEWORK_HEADERS}
        ${QUARTZCORE_FRAMEWORK_HEADERS}
        ${APPKIT_FRAMEWORK_HEADERS}
)


add_library(${PROJECT_NAME} STATIC
        "AppleFrameworks.hpp"
        "AppleFrameworks.cpp"
        ${APPLE_FRAMEWORK_HEADERS}
)
set_target_properties(${PROJECT_NAME} PROPERTIES
        PUBLIC_HEADER "AppleFrameworks.hpp"
)
target_include_directories(${PROJECT_NAME} PUBLIC .)
target_compile_definitions(${PROJECT_NAME} PRIVATE -DAPPLE_FRAMEWORKS_CPP_INSIDE)
