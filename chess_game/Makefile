EXEC = chess
SRC = chess_game.c set_board.c show_moves.c movement.c init_game.c
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lraylib -lm -ldl -lpthread -lGL -lrt -lX11

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $@ $(LDFLAGS)

clean:
	rm -f $(EXEC) *.o

re: clean all

.PHONY: all clean re
