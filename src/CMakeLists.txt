cmake_minimum_required(VERSION 3.13)

add_subdirectory(main)

if (${CMAKE_SYSTEM_NAME} MATCHES "Arduino")
  set(PROJECT_NAME smart_temperature)
  project(${PROJECT_NAME})

  get_board_id(board_id uno)

  add_arduino_executable(${PROJECT_NAME} ${board_id} main.cpp)
  upload_arduino_target(${PROJECT_NAME} ${board_id} /dev/cu.usbmodem14301)

  find_arduino_library(liquid_crystal LiquidCrystal ${board_id})
  link_arduino_library(${PROJECT_NAME} liquid_crystal ${board_id})

  link_arduino_library(${PROJECT_NAME} arduino_driver ${board_id})

  link_arduino_library(${PROJECT_NAME} smart_temperature_lib ${board_id})
#  target_link_libraries(${PROJECT_NAME} PUBLIC arduino_driver)
endif ()

