#ifndef UTILS_H
#define UTILS_H

#include "tetris.h"

// Bag system (7-bag randomizer)
void init_bag_system(void);
int get_next_piece(void);
void get_next_queue(int *queue, int count);

// Line clearing
int check_and_clear_lines(char **map);

// Map management
char** init_map(void);
void draw_map(char **map);
void draw_grid(void);
void draw_ui(GameState *state, int *next_queue);

#endif