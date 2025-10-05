#include "pieces.h"

void rotate_piece(char **map, Piece *piece, int direction)
{
    int old_rotation = piece->rotation;
    int old_x = piece->x;
    
    piece->rotation = (piece->rotation + direction + 4) % 4;
    
    // Wall kicks
    int kicks[] = {0, SIZE_SQUARE, -SIZE_SQUARE, SIZE_SQUARE * 2, -SIZE_SQUARE * 2};
    
    for (int i = 0; i < 5; i++)
    {
        piece->x = old_x + kicks[i];
        
        if (is_position_valid(map, piece))
            return;
    }
    
    // Échec - restaure
    piece->rotation = old_rotation;
    piece->x = old_x;
}