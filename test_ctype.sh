#!/bin/sh
cat ctype.h test_ctype.c > /tmp/program.c
./c4 /tmp/program.c
