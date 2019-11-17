#!/usr/bin/env bash
set -e
set +x

cmake -H. -Bbuild # -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON
cmake --build build
./build/test/arduino_tdd_cpp_test
