.PHONY: all clean

all: c4

c4: c4.c
	gcc c4.c -o c4 -Wall -Wextra -pedantic

clean:
	rm -f c4
