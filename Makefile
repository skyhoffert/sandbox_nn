
CC = gcc
CFLAGS = -Wall -Werror
CLIB = 

all: nn0

nn0: src/nn0.c
	$(CC) $(CFLAGS) -o bin/nn0 src/nn0.c $(CLIBS)
