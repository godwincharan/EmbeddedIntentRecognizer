cmake_minimum_required(VERSION 3.8)

set(This IntentRecognizer)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON) 

include_directories(${IntentRecognizer_SOURCE_DIR}/lib/state_machine_generator/include)
include_directories(${IntentRecognizer_SOURCE_DIR}/lib/state_machine/include)
include_directories(${IntentRecognizer_SOURCE_DIR}/lib/utils/include)

set(Sources
    main.cpp
)
add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    StateMachineGenerator
    StateMachine
    Utils
)

add_custom_target(copy-runtime-files ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${IntentRecognizer_SOURCE_DIR}/data ${CMAKE_CURRENT_BINARY_DIR}/data
    DEPENDS ${MY_TARGET})
