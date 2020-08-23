cmake_minimum_required(VERSION 3.8)

set(This Report)

include_directories(${IntentRecognizer_SOURCE_DIR}/lib/state_machine_generator/include)
include_directories(${IntentRecognizer_SOURCE_DIR}/lib/state_machine/include)
include_directories(${IntentRecognizer_SOURCE_DIR}/lib/utils/include)

set(Sources
    report.cpp
)
add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    StateMachineGenerator
    StateMachine
    Utils
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
