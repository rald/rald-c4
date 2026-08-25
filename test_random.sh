#!/bin/sh
MY_DIR="$(dirname "$0")"
MY_TMP="${TMPDIR:-/tmp}"
cat random.h test_random.c > $TMPDIR/program.c
./c4 $TMPDIR/program.c
