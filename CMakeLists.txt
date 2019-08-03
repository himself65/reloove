cmake_minimum_required(VERSION 3.12)
project(reloove)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out CACHE STRING "" )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out CACHE STRING "" )
set(LIBUV_DIR deps/libuv)

include_directories(${LIBUV_DIR}/include)

link_directories(${LIBUV_DIR})

add_subdirectory(${LIBUV_DIR} out/libuv)

add_executable(reloove lib/reloove.cpp)

find_library(uv out)

target_link_libraries(reloove uv)
