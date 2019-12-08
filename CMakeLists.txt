cmake_minimum_required(VERSION 3.13)
#set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/Arduino-Toolchain.cmake)
project(smart_temperature)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Arduino")
  add_subdirectory(lib/googletest)
  include_directories("${gtest_SOURCE_DIR}/include")
  include_directories("${gmock_SOURCE_DIR}/include")
  add_subdirectory(lib/arduino-mock)
  include_directories(${ARDUINO_MOCK_INCLUDE_DIRS})
endif ()

add_subdirectory(driver)
add_subdirectory(smart_temperature_lib)
add_subdirectory(app)