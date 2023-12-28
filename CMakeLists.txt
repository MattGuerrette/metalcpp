cmake_minimum_required(VERSION 3.24)
project(AppleFrameworksCpp DESCRIPTION "Apple Platform Framework C++ bindings")

set(CMAKE_CXX_STANDARD 23)

function(GroupSourcesByFolder target)
    set(SOURCE_GROUP_DELIMITER "/")
    set(last_dir "")
    set(files "")

    get_target_property(sources ${target} SOURCES)

    foreach (file ${sources})
        file(RELATIVE_PATH relative_file "${PROJECT_SOURCE_DIR}" ${file})
        get_filename_component(dir "${relative_file}" PATH)
        if (NOT "${dir}" STREQUAL "${last_dir}")
            if (files)
                source_group("${last_dir}" FILES ${files})
            endif ()
            set(files "")
        endif ()
        set(files ${files} ${file})
        set(last_dir "${dir}")
    endforeach ()

    if (files)
        source_group("${last_dir}" FILES ${files})
    endif ()
endfunction()

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
        AppleFrameworks.hpp
        AppleFrameworks.cpp
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
        ${APPLE_FRAMEWORK_HEADERS}
)
GroupSourcesByFolder(${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES
        PUBLIC_HEADER "AppleFrameworks.hpp"
)
target_include_directories(${PROJECT_NAME} PUBLIC .)
target_compile_definitions(${PROJECT_NAME} PRIVATE -DAPPLE_FRAMEWORKS_CPP_INSIDE)
