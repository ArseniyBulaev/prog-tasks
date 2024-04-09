cmake_minimum_required(VERSION 3.5)
project(sum_of_k_to_T LANGUAGES CXX)
add_executable(myExe main.cpp)
target_compile_options(myExe PRIVATE -Wall -Wextra -Wpedantic)