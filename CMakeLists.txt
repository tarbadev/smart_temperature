cmake_minimum_required(VERSION 3.13)
#set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/Arduino-Toolchain.cmake)
project(smart_temperature)

set(CMAKE_CXX_STANDARD 11)

option(BUILD_TESTS "Build test programs" OFF)

if (BUILD_TESTS)
  add_subdirectory(lib/googletest)
  include_directories("${gtest_SOURCE_DIR}/include")
  include_directories("${gmock_SOURCE_DIR}/include")
  add_subdirectory(lib/arduino-mock)
  include_directories(${ARDUINO_MOCK_INCLUDE_DIRS})
endif ()

add_subdirectory(driver)
add_subdirectory(smart_temperature_lib)
add_subdirectory(app)