#!/bin/sh
cat ctype.h test_ctype.c > $TMPDIR/program.c
./c4 $TMPDIR/program.c
