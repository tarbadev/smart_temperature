cmake_minimum_required(VERSION 3.13)
set(PROJECT_NAME smart_temperature_lib_test)
project(${PROJECT_NAME})

include_directories(include)

file(GLOB _SRCS src/*.cpp)

add_executable(${PROJECT_NAME} ${_SRCS})

target_link_libraries(${PROJECT_NAME} smart_temperature_lib driver gmock gtest_main)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/include
)