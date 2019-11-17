cmake_minimum_required(VERSION 3.7.2)

configure_file(CMakeLists.txt.in arduino-mock-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/arduino-mock-download )
if(result)
  message(FATAL_ERROR "CMake step for arduino-mock failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/arduino-mock-download )
if(result)
  message(FATAL_ERROR "Build step for arduino-mock failed: ${result}")
endif()

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/arduino-mock-src
    ${CMAKE_CURRENT_BINARY_DIR}/arduino-mock-build
    EXCLUDE_FROM_ALL)

set(ARDUINO_MOCK_INCLUDE_DIRS ${CMAKE_CURRENT_BINARY_DIR}/arduino-mock-src PARENT_SCOPE)