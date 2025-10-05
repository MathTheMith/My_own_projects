CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LDFLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/game/game_logic.c \
       $(SRC_DIR)/game/input_handler.c \
       $(SRC_DIR)/render/draw_game.c \
       $(SRC_DIR)/render/draw_pieces.c \
       $(SRC_DIR)/pieces/piece_collision.c \
       $(SRC_DIR)/pieces/piece_lock.c \
       $(SRC_DIR)/pieces/piece_rotation.c \
       $(SRC_DIR)/utils/bag_system.c \
       $(SRC_DIR)/utils/line_clear.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
NAME = tetris.exe

all: create_dirs $(NAME)

create_dirs:
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	@if not exist $(OBJ_DIR)\game mkdir $(OBJ_DIR)\game
	@if not exist $(OBJ_DIR)\render mkdir $(OBJ_DIR)\render
	@if not exist $(OBJ_DIR)\pieces mkdir $(OBJ_DIR)\pieces
	@if not exist $(OBJ_DIR)\utils mkdir $(OBJ_DIR)\utils

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	@echo Build complete!

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/game/game_logic.o: $(SRC_DIR)/game/game_logic.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/game/input_handler.o: $(SRC_DIR)/game/input_handler.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/render/draw_game.o: $(SRC_DIR)/render/draw_game.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/render/draw_pieces.o: $(SRC_DIR)/render/draw_pieces.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/pieces/piece_collision.o: $(SRC_DIR)/pieces/piece_collision.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/pieces/piece_lock.o: $(SRC_DIR)/pieces/piece_lock.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/pieces/piece_rotation.o: $(SRC_DIR)/pieces/piece_rotation.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/utils/bag_system.o: $(SRC_DIR)/utils/bag_system.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/utils/line_clear.o: $(SRC_DIR)/utils/line_clear.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)
	@if exist $(NAME) del /q $(NAME)
	@echo Clean complete!

rebuild: clean all

.PHONY: all clean rebuild create_dirs