#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include "raylib.h"

#define BOARD_SIZE 10

extern Texture2D wR, bR, wN, bN, wB, bB, wK, bK, wQ, bQ, wP, bP;

bool is_piece_on_square(Texture2D board[BOARD_SIZE][BOARD_SIZE], int x, int y);
bool can_capture(Texture2D board[BOARD_SIZE][BOARD_SIZE], int x, int y, int old_x, int old_y);
void set_board();
void show_possibles_moves(Texture2D board[BOARD_SIZE][BOARD_SIZE], int x, int y);
void show_rook_moves(int x, int y, Texture2D board[BOARD_SIZE][BOARD_SIZE]);
void show_bishop_moves(int x, int y, Texture2D board[BOARD_SIZE][BOARD_SIZE]);
void show_queen_moves(int x, int y, Texture2D board[BOARD_SIZE][BOARD_SIZE]);
void show_king_moves(int x, int y, Texture2D board[BOARD_SIZE][BOARD_SIZE]);
void show_knight_moves(int x, int y, Texture2D board[BOARD_SIZE][BOARD_SIZE]);
bool is_valid_move(int x, int y, Texture2D board[BOARD_SIZE][BOARD_SIZE]);
void show_wpawns_moves(int x, int y, Texture2D board[BOARD_SIZE][BOARD_SIZE]);
void show_bpawns_moves(int x, int y, Texture2D board[BOARD_SIZE][BOARD_SIZE]);


#endif
