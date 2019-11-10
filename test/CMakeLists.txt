cmake_minimum_required(VERSION 3.7.2)
set(PROJECT_NAME arduino_tdd_cpp_test)
project(${PROJECT_NAME})

if (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Arduino")
  add_subdirectory(lib/googletest)

  #include_directories(${ARDUINO_TDD_CPP_HEADERS_DIR})

  set(SOURCE_FILES src/ExampleTest.cpp)

  add_executable(${PROJECT_NAME} ${SOURCE_FILES})
  target_link_libraries(${PROJECT_NAME} gtest_main gtest gmock)
endif ()