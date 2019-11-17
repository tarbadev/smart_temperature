cmake_minimum_required(VERSION 3.7.2)
#set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
project(arduino_tdd_cpp)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(ARDUINO_TDD_CPP_HEADERS_DIR ${PROJECT_SOURCE_DIR}/include)

if (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Arduino")
  add_subdirectory(lib/googletest)
  include_directories("${gtest_SOURCE_DIR}/include")
  include_directories("${gmock_SOURCE_DIR}/include")
  add_subdirectory(lib/arduino-mock)
  include_directories(${ARDUINO_MOCK_INCLUDE_DIRS})
  add_subdirectory(test)
endif ()

add_subdirectory(src)