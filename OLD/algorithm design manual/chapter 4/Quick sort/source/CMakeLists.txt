cmake_minimum_required(VERSION 3.5)
project(quick_sort LANGUAGES CXX)
add_executable(myExe main.cpp)
target_compile_options(myExe PRIVATE -Wall -Wextra -Wpedantic)