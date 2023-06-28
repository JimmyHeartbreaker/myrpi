project(Starfield)
set(CMAKE_SYSTEM_PROCESSOR aarch64)
cmake_minimum_required(VERSION 3.0)
set(CMAKE_C_COMPILER "/usr/bin/aarch64-linux-gnu-gcc-11")
set(CMAKE_CXX_COMPILER "/usr/bin/aarch64-linux-gnu-g++-11")

add_executable(Starfield main.cpp)