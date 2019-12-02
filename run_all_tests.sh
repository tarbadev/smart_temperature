#!/usr/bin/env bash
set -e
set +x

cmake -H. -Bbuild # -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON
cmake --build build --target smart_temperature_test
./build/test/smart_temperature_test
