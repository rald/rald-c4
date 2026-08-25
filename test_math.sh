#!/bin/sh
MY_DIR="$(dirname "$0")"
MY_TMP="${TMPDIR:-/tmp}"
cat math.h test_math.c > $MY_TMP/program.c
./c4 $MY_TMP/program.c
