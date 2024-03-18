cmake_minimum_required(VERSION 3.5)
project(jolly_jumpers LANGUAGES CXX)
add_executable(myExe main.cpp)
add_compile_options(-lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE)