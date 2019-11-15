cmake_minimum_required(VERSION 3.7.2)

set(PROJECT_NAME arduino_tdd_cpp_lib)
project(${PROJECT_NAME})

include_directories(${ARDUINO_TDD_CPP_HEADERS_DIR})
set(SOURCE_FILES TemperatureSensor.cpp)

add_library(${PROJECT_NAME} SHARED STATIC ${SOURCE_FILES})