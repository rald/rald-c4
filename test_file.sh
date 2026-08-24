#!/bin/sh
MY_DIR="$(dirname "$0")"
MY_TMP="${TMPDIR:-/tmp}"
cat ctype.h string.h test_file.c > "$MY_TMP/program.c"
"$MY_DIR/c4" "$MY_TMP/program.c"
