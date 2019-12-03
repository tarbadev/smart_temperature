cmake_minimum_required(VERSION 3.13)
set(PROJECT_NAME arduino_driver_test)
project(${PROJECT_NAME})

file(GLOB _SRCS src/*.cpp)

add_executable(${PROJECT_NAME} ${_SRCS})
target_link_libraries(${PROJECT_NAME} arduino_driver driver arduino-mock gmock gtest_main)