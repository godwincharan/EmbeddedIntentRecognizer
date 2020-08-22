cmake_minimum_required(VERSION 3.8)

set(This StateMachine)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON) 

include_directories(include)

set(Headers
    include/state_manager.h
)
set(Sources
    src/state_manager.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})
