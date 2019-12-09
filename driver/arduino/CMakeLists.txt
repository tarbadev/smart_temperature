cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME arduino_driver)
project(
    ${PROJECT_NAME}
    VERSION 0.0.1
    LANGUAGES CXX
    DESCRIPTION "Driver for Arduino"
)

file(GLOB _SRCS src/*.cpp)

add_library(${PROJECT_NAME} STATIC ${_SRCS})

target_link_libraries(${PROJECT_NAME} PUBLIC driver)

if (${CMAKE_SYSTEM_NAME} MATCHES "Arduino")
  get_board_id(board_id uno)

  add_arduino_core_lib(${PROJECT_NAME} ${board_id})

  find_arduino_library(${PROJECT_NAME}_liquid_crystal LiquidCrystal ${board_id} HEADER_ONLY)
  link_arduino_library(${PROJECT_NAME} ${PROJECT_NAME}_liquid_crystal ${board_id} HEADER_ONLY)
endif ()

if (BUILD_TESTS)
  add_subdirectory(test)
endif ()