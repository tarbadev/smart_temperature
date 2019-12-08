#!/usr/bin/env bash
set -e
set +x

cmake -H. -Bbuild # -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON

cmake --build build --target arduino_driver_test
./build/driver/arduino/test/arduino_driver_test

cmake --build build --target smart_temperature_lib_test
./build/smart_temperature_lib/test/smart_temperature_lib_test

cmake --build build --target application_test
./build/app/test/application_test
