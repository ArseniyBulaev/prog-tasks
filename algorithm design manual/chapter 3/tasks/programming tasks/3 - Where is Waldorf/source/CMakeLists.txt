cmake_minimum_required(VERSION 3.5)
project(where_is_waldorf LANGUAGES CXX)
add_executable(myExe main.cpp)
target_compile_options(myExe PRIVATE -Wall -Wextra -Wpedantic)