#!/bin/sh
cat conio.h test_color.c > $TMPDIR/program.c
./c4 $TMPDIR/program.c
