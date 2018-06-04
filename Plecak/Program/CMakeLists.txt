cmake_minimum_required(VERSION 3.10)
project(Program)

set(CMAKE_CXX_STANDARD 17)

add_executable(Program main.cpp cmake-build-debug/plecak.cpp cmake-build-debug/plecak.h)
MATH(EXPR stack_size "1048 * 1024 * 1024") # 16 Mb
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")