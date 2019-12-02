cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME smart_temperature_lib)
project(${PROJECT_NAME})

file(GLOB _SRCS *.cpp)

include_directories(include)

if (${CMAKE_SYSTEM_NAME} MATCHES "Arduino")
  add_library(${PROJECT_NAME} STATIC ${_SRCS})

  target_link_libraries(${PROJECT_NAME} PUBLIC arduino_driver)
else ()
  include_directories(stub)
  add_library(${PROJECT_NAME} SHARED STATIC ${_SRCS} stub/dtostrf.c)
endif ()

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
      $<INSTALL_INTERFACE:include>
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)