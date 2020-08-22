cmake_minimum_required(VERSION 3.8)

set(This IntentRecognizer)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON) 

enable_testing()

add_subdirectory(lib)
add_subdirectory(test)
add_subdirectory(cli)
add_subdirectory(third_party)
