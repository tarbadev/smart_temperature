#!/usr/bin/env bash
set -e
set +x

cmake -H. -Bbuild -DCMAKE_TOOLCHAIN_FILE=cmake/ArduinoToolchain.cmake
cmake --build build --target smart_temperature-upload
