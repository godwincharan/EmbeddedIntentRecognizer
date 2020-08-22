cmake_minimum_required(VERSION 3.8)

set(This StateMachineTests)

include_directories(${IntentRecognizer_SOURCE_DIR}/lib/state_machine/include)

set(Sources
    state_manager_test.cpp
)
add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    StateMachine
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
