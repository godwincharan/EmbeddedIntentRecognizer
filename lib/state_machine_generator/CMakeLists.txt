cmake_minimum_required(VERSION 3.8)

set(This StateMachineGenerator)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON) 

include_directories(${IntentRecognizer_SOURCE_DIR}/lib/state_machine/include)
include_directories(include)

set(Headers
    include/state_machine_factory.h
)
set(Sources
    src/state_machine_factory.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})
