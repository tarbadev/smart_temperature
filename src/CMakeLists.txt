cmake_minimum_required(VERSION 3.7.2)
add_subdirectory(main)
if (${CMAKE_SYSTEM_NAME} MATCHES "Arduino")
  set(PROJECT_NAME arduino_tdd_cpp)

  set(${PROJECT_NAME}_BOARD uno)
  # set(ARDUINO_CPU)
  project(${PROJECT_NAME})

  # Define additional source and header files or default arduino sketch files
  # set(${PROJECT_NAME}_SRCS)
  set(${PROJECT_NAME}_HDRS User_Setup.h)

  ### Additional static libraries to include in the target.
  set(${PROJECT_NAME}_LIBS arduino_tdd_cpp_lib)

  ### Main sketch file
  set(${PROJECT_NAME}_SKETCH arduino_tdd_cpp.ino)

  ### Additional settings to add non-standard or your own Arduino libraries.
  # For this example (libs will contain additional arduino libraries)
  # An Arduino library my_lib will contain files in libs/my_lib/: my_lib.h, my_lib.cpp + any other cpp files
  # link_directories(${CMAKE_CURRENT_SOURCE_DIR}/)

  # For nested library sources replace ${LIB_NAME} with library name for each library
  # set(_RECURSE true)

  #### Additional settings for programmer. From programmers.txt
  # set(${PROJECT_NAME}_PROGRAMMER avrispmkii)
  set(${PROJECT_NAME}_PORT /dev/cu.usbmodem14401)
  # set(uno.upload.speed 9600)

  ## Verbose build process
  # set(${PROJECT_NAME}_AFLAGS -v)

  generate_arduino_firmware(${PROJECT_NAME})
endif ()