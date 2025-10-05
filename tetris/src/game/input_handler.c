#include "tetris.h"
#include "game.h"
#include "pieces.h"
#include "utils.h"

static int move_counter = 0;
static int lock_delay = 0;
static int is_grounded = 0;

void handle_input(GameState *state)
{
    int gp = state->gamepad_id;
    
    if (!IsGamepadAvailable(gp))
    {
        DrawText("Manette non détectée!", 300, 500, 20, RED);
        return;
    }
    
    // Mouvements latéraux
    if (IsGamepadButtonDown(gp, GAMEPAD_BUTTON_LEFT_FACE_LEFT) ||
        GetGamepadAxisMovement(gp, GAMEPAD_AXIS_LEFT_X) < -0.5)
    {
        if (move_counter > 3)
        {
            if (can_move(state->map, &state->current, 'l'))
            {
                state->current.x -= SIZE_SQUARE;
                lock_delay = 0;
            }
            move_counter = 0;
        }
        move_counter++;
    }
    else if (IsGamepadButtonDown(gp, GAMEPAD_BUTTON_LEFT_FACE_RIGHT) ||
             GetGamepadAxisMovement(gp, GAMEPAD_AXIS_LEFT_X) > 0.5)
    {
        if (move_counter > 3)
        {
            if (can_move(state->map, &state->current, 'r'))
            {
                state->current.x += SIZE_SQUARE;
                lock_delay = 0;
            }
            move_counter = 0;
        }
        move_counter++;
    }
    else
    {
        move_counter = 0;
    }
    
    // Rotations
    if (IsGamepadButtonPressed(gp, GAMEPAD_BUTTON_RIGHT_FACE_DOWN))
        rotate_piece(state->map, &state->current, 1);
    
    if (IsGamepadButtonPressed(gp, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT))
        rotate_piece(state->map, &state->current, -1);
    
    // Hard drop
    if (IsGamepadButtonPressed(gp, GAMEPAD_BUTTON_LEFT_FACE_UP))
    {
        while (can_move(state->map, &state->current, 'd'))
            state->current.y += SIZE_SQUARE;
        
        lock_piece(state->map, &state->current);
        int lines = check_and_clear_lines(state->map);
        state->score += lines * 100;
        
        state->current.type = get_next_piece();
        state->current.x = 395;
        state->current.y = 150;
        state->current.rotation = 0;
        state->can_hold = 1;
        is_grounded = 0;
        lock_delay = 0;
        return;
    }
    
    // Soft drop
    if (IsGamepadButtonDown(gp, GAMEPAD_BUTTON_LEFT_FACE_DOWN))
    {
        if (can_move(state->map, &state->current, 'd'))
        {
            state->current.y += SIZE_SQUARE;
            state->frame_counter = 0;
        }
    }
    
    // Hold
    if (IsGamepadButtonPressed(gp, GAMEPAD_BUTTON_LEFT_TRIGGER_1) && state->can_hold)
    {
        if (state->held_piece == -1)
        {
            state->held_piece = state->current.type;
            state->current.type = get_next_piece();
        }
        else
        {
            int temp = state->current.type;
            state->current.type = state->held_piece;
            state->held_piece = temp;
        }
        state->current.x = 395;
        state->current.y = 150;
        state->current.rotation = 0;
        state->can_hold = 0;
    }
    
    // Gravité
    if (state->frame_counter > 10)
    {
        if (can_move(state->map, &state->current, 'd'))
        {
            state->current.y += SIZE_SQUARE;
            is_grounded = 0;
            lock_delay = 0;
        }
        else
        {
            is_grounded = 1;
        }
        state->frame_counter = 0;
    }
    
    // Lock delay
    if (is_grounded)
    {
        if (lock_delay >= 60)
        {
            lock_piece(state->map, &state->current);
            int lines = check_and_clear_lines(state->map);
            state->score += lines * 100;
            
            state->current.type = get_next_piece();
            state->current.x = 395;
            state->current.y = 150;
            state->current.rotation = 0;
            state->can_hold = 1;
            is_grounded = 0;
            lock_delay = 0;
        }
        else
        {
            lock_delay++;
        }
    }
}