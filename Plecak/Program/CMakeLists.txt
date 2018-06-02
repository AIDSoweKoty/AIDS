cmake_minimum_required(VERSION 3.10)
project(Program)

set(CMAKE_CXX_STANDARD 17)

add_executable(Program main.cpp cmake-build-debug/plecak.cpp cmake-build-debug/plecak.h)