cmake_minimum_required(VERSION 3.7.2)

set(PROJECT_NAME arduino_tdd_cpp_lib)
project(${PROJECT_NAME})

include_directories(${ARDUINO_TDD_CPP_HEADERS_DIR})
set(SOURCE_FILES SmartTemperature.cpp ArduinoLogger.cpp ArduinoTemperatureSensor.cpp)

if (${CMAKE_SYSTEM_NAME} MATCHES "Arduino")
  generate_arduino_library(${PROJECT_NAME}
      SRCS ${SOURCE_FILES}
      BOARD uno)
else ()
  add_library(${PROJECT_NAME} SHARED STATIC ${SOURCE_FILES})
endif ()