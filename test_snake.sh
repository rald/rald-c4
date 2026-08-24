#!/bin/sh
MY_DIR="$(dirname "$0")"
MY_TMP="${TMPDIR:-/tmp}"
cat conio.h random.h test_snake.c > "$MY_TMP/program.c"
"$MY_DIR/c4" "$MY_TMP/program.c"

