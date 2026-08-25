#!/bin/sh
MY_DIR="$(dirname "$0")"
MY_TMP="${TMPDIR:-/tmp}"
cat ctype.h string.h test_string.c > $TMPDIR/program.c
./c4 $TMPDIR/program.c
