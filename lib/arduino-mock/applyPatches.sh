#!/usr/bin/env bash

set -e
set +x

PATCHES_DIR="$1/*.patch"

for patch in $PATCHES_DIR; do
  echo "Applying patch $patch"
  patch -p1 < "$patch"
done
