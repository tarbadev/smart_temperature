cmake_minimum_required(VERSION 3.13)
set(PROJECT_NAME smart_temperature_test)
project(${PROJECT_NAME})

include_directories(${SMART_TEMPERATURE_HEADERS_DIR})
include_directories(src/include)

file(GLOB SRC_FILES src/*.cpp)
set(SOURCE_FILES ${SRC_FILES} ../src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} smart_temperature_lib gmock gtest_main arduino-mock)