cmake_minimum_required(VERSION 3.8)

set(This StateMachineGeneratorTests)

include_directories(${IntentRecognizer_SOURCE_DIR}/lib/state_machine_generator/include)
include_directories(${IntentRecognizer_SOURCE_DIR}/lib/state_machine/include)

set(Sources
    state_machine_factory_test.cpp
)
add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    StateMachineGenerator
    StateMachine
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
