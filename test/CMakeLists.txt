cmake_minimum_required(VERSION 3.13)
set(PROJECT_NAME application_test)
project(${PROJECT_NAME})

include_directories(src/include)

file(GLOB _SRCS src/*.cpp)

add_executable(${PROJECT_NAME} ${_SRCS} ${CMAKE_SOURCE_DIR}/src/main.cpp)
target_link_libraries(${PROJECT_NAME} smart_temperature_lib driver arduino_driver driver arduino-mock gmock gtest_main)