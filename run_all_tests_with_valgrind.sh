#!/usr/bin/env bash
set -e
set +x

cmake -H. -Bbuild # -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON

cmake --build build --target arduino_driver_test
valgrind --leak-check=full --show-leak-kinds=all "$(pwd)/build/driver/arduino/test/arduino_driver_test"

cmake --build build --target smart_temperature_lib_test
valgrind --leak-check=full --show-leak-kinds=all "$(pwd)/build/src/smart_temperature_lib/test/smart_temperature_lib_test"

cmake --build build --target application_test
valgrind --leak-check=full --show-leak-kinds=all "$(pwd)/build/test/application_test"