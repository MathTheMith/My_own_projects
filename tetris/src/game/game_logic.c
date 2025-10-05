#include "tetris.h"
#include "game.h"
#include "pieces.h"
#include "utils.h"

static int next_queue[5];

GameState* init_game(void)
{
    GameState *state = malloc(sizeof(GameState));
    
    state->map = init_map();
    state->held_piece = -1;
    state->can_hold = 1;
    state->frame_counter = 0;
    state->score = 0;
    state->gamepad_id = 0;
    
    // Détection manette
    for (int i = 0; i < 4; i++)
    {
        if (IsGamepadAvailable(i))
        {
            printf("Gamepad %d: %s\n", i, GetGamepadName(i));
            state->gamepad_id = i;
            break;
        }
    }
    
    // Initialise le système de pièces
    srand(time(NULL));
    init_bag_system();
    get_next_queue(next_queue, 5);
    
    // Première pièce
    state->current.type = get_next_piece();
    state->current.x = 395;
    state->current.y = 150;
    state->current.rotation = 0;
    
    return state;
}

void free_game(GameState *state)
{
    for (int i = 0; i < MAP_HEIGHT; i++)
        free(state->map[i]);
    free(state->map);
    free(state);
}

void update_game(GameState *state)
{
    handle_input(state);
    
    get_next_queue(next_queue, 5);
    draw_map(state->map);
    draw_ui(state, next_queue);
    draw_piece(&state->current);
    
    state->frame_counter++;
}

int check_game_over(char **map)
{
    for (int j = 0; j < MAP_WIDTH; j++)
    {
        if (map[0][j] != 0)
        {
            printf("GAME OVER! Final Score: \n");
            return 1;
        }
    }
    return 0;
}