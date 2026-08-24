#!/bin/sh
MY_DIR="$(dirname "$0")"
MY_TMP="${TMPDIR:-/tmp}"
cat test_io.c > "$MY_TMP/program.c"
"$MY_DIR/c4" "$MY_TMP/program.c"
