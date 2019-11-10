cmake_minimum_required(VERSION 3.7.2)
#set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
project(arduino_tdd_cpp)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#set(ARDUINO_TDD_CPP_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/arduino-tdd-cpp)

add_subdirectory(src)
add_subdirectory(test)