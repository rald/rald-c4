#!/bin/sh
cat math.h test_math.c > $TMPDIR/program.c
./c4 $TMPDIR/program.c
