
CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -Werror
CINCLUDES=-Iinclude/
CLIBS=

all: sandbox_nn

obj/node.o: src/node.c include/node.h
	$(CC) $(CFLAGS) $(CINCLUDES) -o obj/node.o -c src/node.c $(CLIBS)

sandbox_nn: src/sandbox_nn.c include/node.h obj/node.o
	$(CC) $(CFLAGS) $(CINCLUDES) -o sandbox_nn src/sandbox_nn.c \
		obj/node.o \
		$(CLIBS)
