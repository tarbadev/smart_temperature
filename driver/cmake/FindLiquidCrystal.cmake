# FindLiquidCrystal.cmake
#
# Finds the arduino library
#
# This will define the following variables
#
#    LiquidCrystal_FOUND
#    LiquidCrystal_INCLUDE_DIRS
#
# and the following imported targets
#
#     LiquidCrystal::LiquidCrystal

find_package(PkgConfig)
pkg_check_modules(PC_LiquidCrystal QUIET LiquidCrystal)

set(PC_ARDUINO_JAVA_LIBRARIES_DIR /Applications/Arduino.app/Contents/Java/libraries)

find_path(LiquidCrystal_INCLUDE_DIR
    NAMES LiquidCrystal.h
    PATHS ${PC_ARDUINO_JAVA_LIBRARIES_DIR}
    PATH_SUFFIXES LiquidCrystal/src
    )

set(LiquidCrystal_VERSION ${PC_LiquidCrystal_VERSION})

mark_as_advanced(LiquidCrystal_FOUND LiquidCrystal_INCLUDE_DIR LiquidCrystal_VERSION)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(LiquidCrystal
    REQUIRED_VARS LiquidCrystal_INCLUDE_DIR
    VERSION_VAR LiquidCrystal_VERSION
    )

if(LiquidCrystal_FOUND)
  set(LiquidCrystal_INCLUDE_DIRS ${LiquidCrystal_INCLUDE_DIR})
endif()

if(LiquidCrystal_FOUND AND NOT TARGET LiquidCrystal::LiquidCrystal)
  add_library(LiquidCrystal::LiquidCrystal INTERFACE IMPORTED)
  set_target_properties(LiquidCrystal::LiquidCrystal PROPERTIES
      INTERFACE_INCLUDE_DIRECTORIES "${LiquidCrystal_INCLUDE_DIR}"
      )
endif()
