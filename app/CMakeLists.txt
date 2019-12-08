cmake_minimum_required(VERSION 3.13)
project(smart_temperature_app)

add_subdirectory(src)

if (BUILD_TESTS)
  add_subdirectory(test)
endif ()