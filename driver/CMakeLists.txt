cmake_minimum_required(VERSION 3.13)
project(
    arduino-driver
    VERSION 0.0.1
    LANGUAGES CXX
    DESCRIPTION "Driver for Arduino"
)

#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

file(GLOB _SRCS src/*.cpp)

add_library(arduino_driver STATIC ${_SRCS})

target_include_directories(
    arduino_driver
    PUBLIC
      $<INSTALL_INTERFACE:include>
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

get_board_id(board_id uno)

add_arduino_core_lib(arduino_driver ${board_id})

find_arduino_library(arduino_driver_liquid_crystal LiquidCrystal ${board_id} HEADER_ONLY)
link_arduino_library(arduino_driver arduino_driver_liquid_crystal ${board_id} HEADER_ONLY)