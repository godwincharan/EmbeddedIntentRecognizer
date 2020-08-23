cmake_minimum_required(VERSION 3.8)

set(This Utils)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON) 

include_directories(include)

set(Headers
    include/string_utils.h
)
set(Sources
    src/string_utils.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})
