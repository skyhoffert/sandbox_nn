
CC = gcc
CFLAGS = -Wall -Werror
CLIBS = 

all: manual_to_gui manual_to_nn nn_tic-tac-toe

clean:
	rm -rf bin/*

manual_to_gui: src/manual_to_gui.c
	$(info Making manual_to_gui.)
	$(CC) $(CFLAGS) -o bin/manual_to_gui src/manual_to_gui.c $(CLIBS)

manual_to_nn: src/manual_to_nn.c
	$(info Making manual_to_nn.)
	$(CC) $(CFLAGS) -o bin/manual_to_nn src/manual_to_nn.c $(CLIBS)

nn_tic-tac-toe: src/nn_tic-tac-toe.c
	$(info Making nn_tic-tac-toe.)
	$(CC) $(CFLAGS) -o bin/nn_tic-tac-toe src/nn_tic-tac-toe.c $(CLIBS)
