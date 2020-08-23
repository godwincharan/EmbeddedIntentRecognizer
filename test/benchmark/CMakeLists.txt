cmake_minimum_required(VERSION 3.8)

set(This BenchmarkTests)

include_directories(${IntentRecognizer_SOURCE_DIR}/lib/state_machine_generator/include)
include_directories(${IntentRecognizer_SOURCE_DIR}/lib/state_machine/include)
include_directories(${IntentRecognizer_SOURCE_DIR}/lib/utils/include)

set(Sources
    benchmark_test.cpp
)
add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    benchmark
    StateMachineGenerator
    StateMachine
    Utils
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
