cmake_minimum_required(VERSION 3.7.2)
set(PROJECT_NAME arduino_tdd_cpp_test)
project(${PROJECT_NAME})

include_directories(${ARDUINO_TDD_CPP_HEADERS_DIR})
include_directories(src/include)

set(SOURCE_FILES src/TemperatureSensorTest.cpp src/LoggerTest.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} arduino_tdd_cpp_lib gmock gtest_main arduino-mock)