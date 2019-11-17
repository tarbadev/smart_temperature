#!/usr/bin/env bash
set -e
set +x

cmake -H. -Bbuild # -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON
cmake --build build
valgrind --leak-check=full --show-leak-kinds=all "$(pwd)/build/test/arduino_tdd_cpp_test"
