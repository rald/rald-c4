#!/bin/sh
cat ctype.h string.h test_string.c > $TMPDIR/program.c
./c4 $TMPDIR/program.c
