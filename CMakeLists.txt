# ------------------------------------------------------------------------------
# Simple Raylib Template
# 
# ------------------------------------------------------------------------------
# Author:
# https://github.com/itsYakub
# ------------------------------------------------------------------------------
# Naming convention:
# - *.c - source file extension
# - *.h - header file extension
# - src/ - source files directory
# - lib/ - libraries directory
# - include/ - header files direcotry
# - res/ - resources / assets directory
# - bin/ - binary / final exec. directory
# ------------------------------------------------------------------------------
# 
# ------------------------------------------------------------------------------
# Most parts of this CMakeLists.txt file fomes from this source:
# https://github.com/raysan5/raylib/tree/master/projects/CMake
# ------------------------------------------------------------------------------
# LICENCE (MIT):
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
# DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
# OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
# OR OTHER DEALINGS IN THE SOFTWARE.
# ------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.14)

project(
    game 
    VERSION 1.0
    DESCRIPTION "Simple C template for Raylib" 
    HOMEPAGE_URL "https://github.com/itsYakub/RaylibGameTemplate"
    LANGUAGES C
)

# Dependencies
set(RAYLIB_VERSION 5.0)
include(FetchContent)
FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
)
FetchContent_GetProperties(raylib)

if (NOT raylib_POPULATED)

    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(raylib_VERBOSE 1)

# Our Project

# Project's source files:
# Edit this variable to include all the source files (*.c, *.cpp, *.cc etc.) that the project requires

file(
    GLOB SOURCES 

    ${CMAKE_SOURCE_DIR}/src/*.c
)


# Project's include directories:
# Edit this variable to include all the directories with necessary header files

set(
    INCLUDE_DIRECTORIES
    ${CMAKE_SOURCE_DIR}/include # default project include directory
    ${CMAKE_SOURCE_DIR}/lib/raylib/src # raysan5/raylib
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} raylib)
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRECTORIES})

if (LINUX)

    target_link_options(${PROJECT_NAME} PRIVATE -static-libgcc -static-libstdc++)

endif()

if (WIN32)

    target_compile_options(${PROJECT_NAME} PRIVATE -mwindows)
    target_link_options(${PROJECT_NAME} PRIVATE -static)

endif()

if (APPLE)

    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")

endif()