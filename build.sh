#!/bin/sh
set -eu

cd "$(dirname "$0")"
mkdir -p build

for source in ./*.c; do
    name=${source##*/}
    name=${name%.c}
    "${CC:-cc}" -std=c89 -pedantic-errors -Wall -Wextra -Werror \
        "$source" -o "build/$name"
done
