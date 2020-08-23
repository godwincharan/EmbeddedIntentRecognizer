cmake_minimum_required(VERSION 3.8)

set(This UtilsTests)

include_directories(${IntentRecognizer_SOURCE_DIR}/lib/utils/include)

set(Sources
    string_utils_test.cpp
)
add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    Utils
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
