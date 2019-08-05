cmake_minimum_required(VERSION 3.1)
project(reloove)

if (MSVC)
    list(APPEND rl_test_flags /MTd)
else ()
    list(APPEND rl_flags -std=c++11)
    list(APPEND rl_test_flags -std=c++11)
endif ()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out CACHE STRING "")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out CACHE STRING "")
set(LIBUV_DIR deps/libuv)
set(GTEST_DIR deps/googletest)
set(rl_source
        lib/TimeData.cpp)
set(rl_test_source
        test/reloove.test.cpp)

include_directories(${LIBUV_DIR}/include)
include_directories(${GTEST_DIR})

link_directories(${LIBUV_DIR} ${GTEST_DIR})
add_subdirectory(${LIBUV_DIR} out/libuv)
add_subdirectory(${GTEST_DIR} out/gtest)

add_library(reloove ${rl_source})
target_compile_options(reloove PRIVATE ${rl_flags})
# Binding uv to reloove
target_link_libraries(reloove uv)

# Test Part
enable_testing()
add_executable(rl_run_tests ${rl_test_source})
target_compile_options(rl_run_tests PRIVATE ${rl_test_flags})
target_include_directories(rl_run_tests PRIVATE include)
target_link_libraries(rl_run_tests reloove gtest gtest_main)
add_test(NAME rl_test
        COMMAND rl_run_tests
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})