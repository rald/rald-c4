#!/bin/sh
cat ctype.h string.h test_file.c > /tmp/program.c
./c4 /tmp/program.c
