#include "tetris.h"
#include "utils.h"
#include "pieces.h"

void draw_grid(void)
{
    Color grid_color = (Color){50, 50, 50, 255};
    
    for (int i = 0; i <= MAP_WIDTH; i++)
    {
        int x = 215 + (i * SIZE_SQUARE);
        DrawLine(x, 100, x, 100 + (MAP_HEIGHT * SIZE_SQUARE), grid_color);
    }
    
    for (int i = 0; i <= MAP_HEIGHT; i++)
    {
        int y = 100 + (i * SIZE_SQUARE);
        DrawLine(215, y, 215 + (MAP_WIDTH * SIZE_SQUARE), y, grid_color);
    }
}

char** init_map(void)
{
    char **map = calloc(MAP_HEIGHT, sizeof(char*));
    for (int i = 0; i < MAP_HEIGHT; i++)
        map[i] = calloc(MAP_WIDTH, sizeof(char));
    return map;
}

static void draw_cube_at(char **map, int i, int j)
{
    Color light_blue = (Color){150, 201, 255, 255};
    int x = (j * SIZE_SQUARE) + 215;
    int y = (i * SIZE_SQUARE) + 100;
    
    Color colors[8] = {
        BLACK, YELLOW, light_blue, VIOLET, 
        GREEN, RED, ORANGE, BLUE
    };
    
    if (map[i][j] >= 1 && map[i][j] <= 7)
        draw_cube(x, y, colors[map[i][j]]);
}

void draw_map(char **map)
{
    DrawLine(215, 100, 215, 1005, WHITE);
    DrawLine(665, 100, 665, 1005, WHITE);
    DrawLine(215, 100, 665, 100, WHITE);
    
    for (int i = 0; i < MAP_HEIGHT; i++)
        for (int j = 0; j < MAP_WIDTH; j++)
            if (map[i][j] != 0)
                draw_cube_at(map, i, j);
}

void draw_ui(GameState *state, int *next_queue)
{
    // Hold piece
    DrawText("HOLD", 70, 100, 20, WHITE);
    if (state->held_piece != -1)
        draw_piece_preview(state->held_piece, 100, 200);
    
    // Next pieces
    DrawText("NEXT", 720, 150, 20, WHITE);
    for (int i = 0; i < 5; i++)
        draw_piece_preview(next_queue[i], 775, 250 + (i * 150));
    
    // Score
    DrawText(TextFormat("SCORE: %d", state->score), 350, 20, 25, WHITE);
} 