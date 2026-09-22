#!/bin/sh
set -eu

cd "$(dirname "$0")"
mkdir -p build

for source in ./*.c; do
    [ -f "$source" ] || continue
    name=$(basename "$source" .c)
    "${CC:-cc}" -std=c99 -pedantic-errors -Wall -Wextra -Werror \
        "$source" -o "build/$name"
done
