cmake_minimum_required(VERSION 3.7.2)

set(PROJECT_NAME smart_temperature_lib)
project(${PROJECT_NAME})

include_directories(${SMART_TEMPERATURE_HEADERS_DIR})
file(GLOB SOURCE_FILES *.cpp)

if (${CMAKE_SYSTEM_NAME} MATCHES "Arduino")
  include_directories(${ARDUINO_LIBRARIES_PATH}/LiquidCrystal/src)

  generate_arduino_library(${PROJECT_NAME}
      SRCS ${SOURCE_FILES}
      BOARD uno)
else ()
  include_directories(stub)
  add_library(${PROJECT_NAME} SHARED STATIC ${SOURCE_FILES} stub/dtostrf.c)
endif ()