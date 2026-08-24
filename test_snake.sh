#!/bin/sh
cat random.h conio.h test_snake.c > $TMPDIR/program.c
./c4 $TMPDIR/program.c
