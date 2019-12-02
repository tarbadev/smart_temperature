# FindArduino.cmake
#
# Finds the arduino library
#
# This will define the following variables
#
#    Arduino_FOUND
#    Arduino_INCLUDE_DIRS
#
# and the following imported targets
#
#     Arduino::Arduino

find_package(PkgConfig)
pkg_check_modules(PC_Arduino QUIET Arduino)

if (${CMAKE_SYSTEM_NAME} MATCHES "Arduino")
  set(PC_ARDUINO_CORES_DIR /Applications/Arduino.app/Contents/Java/hardware/arduino/avr/cores)
else()
  set(PC_ARDUINO_CORES_DIR /Applications/Arduino.app/Contents/Java/hardware/arduino/avr/cores)
endif()

find_path(Arduino_INCLUDE_DIR
    NAMES Arduino.h
    PATHS ${PC_ARDUINO_CORES_DIR}
    PATH_SUFFIXES arduino
    )

set(Arduino_VERSION ${PC_Arduino_VERSION})

mark_as_advanced(Arduino_FOUND Arduino_INCLUDE_DIR Arduino_VERSION)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Arduino
    REQUIRED_VARS Arduino_INCLUDE_DIR
    VERSION_VAR Arduino_VERSION
    )

if (Arduino_FOUND)
  set(
      Arduino_INCLUDE_DIR
      ${Arduino_INCLUDE_DIR}
      /Applications/Arduino.app/Contents/Java/hardware/arduino/avr/variants/standard
  )
  set(Arduino_INCLUDE_DIRS ${Arduino_INCLUDE_DIR})
endif ()

if (Arduino_FOUND AND NOT TARGET Arduino::Arduino)
  add_library(Arduino::Arduino INTERFACE IMPORTED)
  set_target_properties(Arduino::Arduino PROPERTIES
      INTERFACE_INCLUDE_DIRECTORIES "${Arduino_INCLUDE_DIR}"
      )
endif ()
