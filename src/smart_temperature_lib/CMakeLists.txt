cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME smart_temperature_lib)
project(${PROJECT_NAME})

file(GLOB _SRCS src/*.cpp)

if (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Arduino")
  include_directories(stub)
  set(_SRCS ${_SRCS} stub/dtostrf.c)
endif ()

add_library(${PROJECT_NAME} STATIC ${_SRCS})

if (${CMAKE_SYSTEM_NAME} MATCHES "Arduino")
  target_link_libraries(${PROJECT_NAME} PRIVATE arduino_driver)
endif ()

target_link_libraries(${PROJECT_NAME} PRIVATE driver)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
      $<INSTALL_INTERFACE:include>
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)