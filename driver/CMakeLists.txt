cmake_minimum_required(VERSION 3.13)
project(
    driver
    VERSION 0.0.1
    LANGUAGES CXX
    DESCRIPTION "Driver"
)

add_library(driver INTERFACE)

target_include_directories(
    driver
    INTERFACE
      $<INSTALL_INTERFACE:include>
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

add_subdirectory(arduino)