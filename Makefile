
CC = gcc
CFLAGS = -Wall -Werror
CLIBS = 

all: manual_to_gui manual_to_nn

manual_to_gui: src/manual_to_gui.c
	$(info Making manual_to_gui.)
	$(CC) $(CFLAGS) -o bin/manual_to_gui src/manual_to_gui.c $(CLIBS)

manual_to_nn: src/manual_to_nn.c
	$(info Making manual_to_nn.)
	$(CC) $(CFLAGS) -o bin/manual_to_nn src/manual_to_nn.c $(CLIBS)
