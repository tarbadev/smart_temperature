cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME smart_temperature_lib)
project(
    ${PROJECT_NAME}
    VERSION 0.0.1
    LANGUAGES CXX
    DESCRIPTION "Smart Temperature Library, reads temperature and displays it"
)

file(GLOB _SRCS src/*.cpp)

if (BUILD_TESTS)
  include_directories(stub)
  set(_SRCS ${_SRCS} stub/dtostrf.c)
  add_subdirectory(test)
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