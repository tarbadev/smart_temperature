cmake_minimum_required(VERSION 3.13)
set(PROJECT_NAME driver)
project(
    ${PROJECT_NAME}
    VERSION 0.0.1
    LANGUAGES CXX
    DESCRIPTION "Driver"
)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(
    ${PROJECT_NAME}
    INTERFACE
      $<INSTALL_INTERFACE:include>
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

add_subdirectory(arduino)