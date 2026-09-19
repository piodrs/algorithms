#!/bin/sh
set -eu

cd "$(dirname "$0")"
mkdir -p build

for source in ./*.cpp; do
    [ -f "$source" ] || continue
    name=$(basename "$source" .cpp)
    "${CXX:-g++}" -std=c++17 -Wall -Wextra -Wpedantic "$source" -o "build/$name"
done
