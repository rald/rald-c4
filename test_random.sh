#!/bin/sh
cat random.h test_random.c > $TMPDIR/program.c
./c4 $TMPDIR/program.c
