cmake_minimum_required(VERSION 3.8)

set(This StateMachineGenerator)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON) 

include_directories(${IntentRecognizer_SOURCE_DIR}/lib/state_machine/include)
include_directories(include)

set(Headers
    include/state_machine_factory.h
    include/i_reader.h
    include/csv_state_machine_reader.h
    include/json_state_machine_reader.h
    include/xml_state_machine_reader.h
)
set(Sources
    src/state_machine_factory.cpp
    src/csv_state_machine_reader.cpp
    src/json_state_machine_reader.cpp
    src/xml_state_machine_reader.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})
