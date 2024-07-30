cmake_minimum_required(VERSION 3.28)
project(multiCurrencyMoney)

include_directories(source)

add_subdirectory(source)
add_subdirectory(tests)
add_subdirectory(lib/googletest)