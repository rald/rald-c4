#!/bin/sh
cat random.h test_random.c > /tmp/program.c
./c4 /tmp/program.c
