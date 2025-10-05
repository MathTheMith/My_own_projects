#include "pieces.h"

static int check_bounds(int ligne, int colonne)
{
    return (ligne >= 0 && ligne < MAP_HEIGHT && colonne >= 0 && colonne < MAP_WIDTH);
}

static int check_cells(char **map, int cells[][2], int count)
{
    for (int i = 0; i < count; i++)
    {
        int l = cells[i][0];
        int c = cells[i][1];
        if (!check_bounds(l, c) || map[l][c])
            return 0;
    }
    return 1;
}

int is_position_valid(char **map, Piece *piece)
{
    int colonne = (piece->x - 215) / SIZE_SQUARE;
    int ligne = (piece->y - 100) / SIZE_SQUARE;
    int cells[4][2];
    
    if (piece->type == 0) // I
    {
        if (piece->rotation == 0 || piece->rotation == 2)
        {
            cells[0][0] = ligne; cells[0][1] = colonne - 2;
            cells[1][0] = ligne; cells[1][1] = colonne - 1;
            cells[2][0] = ligne; cells[2][1] = colonne;
            cells[3][0] = ligne; cells[3][1] = colonne + 1;
        }
        else
        {
            cells[0][0] = ligne - 2; cells[0][1] = colonne;
            cells[1][0] = ligne - 1; cells[1][1] = colonne;
            cells[2][0] = ligne; cells[2][1] = colonne;
            cells[3][0] = ligne + 1; cells[3][1] = colonne;
        }
        return check_cells(map, cells, 4);
    }
    
    if (piece->type == 1) // O
    {
        cells[0][0] = ligne - 1; cells[0][1] = colonne - 1;
        cells[1][0] = ligne - 1; cells[1][1] = colonne;
        cells[2][0] = ligne; cells[2][1] = colonne - 1;
        cells[3][0] = ligne; cells[3][1] = colonne;
        return check_cells(map, cells, 4);
    }
    
    if (piece->type == 2) // T
    {
        switch (piece->rotation)
        {
            case 0:
                cells[0][0] = ligne; cells[0][1] = colonne - 1;
                cells[1][0] = ligne - 1; cells[1][1] = colonne;
                cells[2][0] = ligne; cells[2][1] = colonne;
                cells[3][0] = ligne; cells[3][1] = colonne + 1;
                break;
            case 1:
                cells[0][0] = ligne - 1; cells[0][1] = colonne;
                cells[1][0] = ligne; cells[1][1] = colonne;
                cells[2][0] = ligne; cells[2][1] = colonne + 1;
                cells[3][0] = ligne + 1; cells[3][1] = colonne;
                break;
            case 2:
                cells[0][0] = ligne; cells[0][1] = colonne - 1;
                cells[1][0] = ligne; cells[1][1] = colonne;
                cells[2][0] = ligne + 1; cells[2][1] = colonne;
                cells[3][0] = ligne; cells[3][1] = colonne + 1;
                break;
            case 3:
                cells[0][0] = ligne - 1; cells[0][1] = colonne;
                cells[1][0] = ligne; cells[1][1] = colonne - 1;
                cells[2][0] = ligne; cells[2][1] = colonne;
                cells[3][0] = ligne + 1; cells[3][1] = colonne;
                break;
        }
        return check_cells(map, cells, 4);
    }
    
    if (piece->type == 3) // S
    {
        if (piece->rotation == 0 || piece->rotation == 2)
        {
            cells[0][0] = ligne; cells[0][1] = colonne - 1;
            cells[1][0] = ligne - 1; cells[1][1] = colonne;
            cells[2][0] = ligne; cells[2][1] = colonne;
            cells[3][0] = ligne - 1; cells[3][1] = colonne + 1;
        }
        else
        {
            cells[0][0] = ligne - 1; cells[0][1] = colonne;
            cells[1][0] = ligne; cells[1][1] = colonne;
            cells[2][0] = ligne; cells[2][1] = colonne + 1;
            cells[3][0] = ligne + 1; cells[3][1] = colonne + 1;
        }
        return check_cells(map, cells, 4);
    }
    
    if (piece->type == 4) // Z
    {
        if (piece->rotation == 0 || piece->rotation == 2)
        {
            cells[0][0] = ligne - 1; cells[0][1] = colonne - 1;
            cells[1][0] = ligne - 1; cells[1][1] = colonne;
            cells[2][0] = ligne; cells[2][1] = colonne;
            cells[3][0] = ligne; cells[3][1] = colonne + 1;
        }
        else
        {
            cells[0][0] = ligne - 1; cells[0][1] = colonne + 1;
            cells[1][0] = ligne; cells[1][1] = colonne;
            cells[2][0] = ligne; cells[2][1] = colonne + 1;
            cells[3][0] = ligne + 1; cells[3][1] = colonne;
        }
        return check_cells(map, cells, 4);
    }
    
    if (piece->type == 5) // L
    {
        switch (piece->rotation)
        {
            case 0:
                cells[0][0] = ligne; cells[0][1] = colonne - 1;
                cells[1][0] = ligne; cells[1][1] = colonne;
                cells[2][0] = ligne; cells[2][1] = colonne + 1;
                cells[3][0] = ligne - 1; cells[3][1] = colonne + 1;
                break;
            case 1:
                cells[0][0] = ligne - 1; cells[0][1] = colonne;
                cells[1][0] = ligne; cells[1][1] = colonne;
                cells[2][0] = ligne + 1; cells[2][1] = colonne;
                cells[3][0] = ligne + 1; cells[3][1] = colonne + 1;
                break;
            case 2:
                cells[0][0] = ligne; cells[0][1] = colonne - 1;
                cells[1][0] = ligne; cells[1][1] = colonne;
                cells[2][0] = ligne; cells[2][1] = colonne + 1;
                cells[3][0] = ligne + 1; cells[3][1] = colonne - 1;
                break;
            case 3:
                cells[0][0] = ligne - 1; cells[0][1] = colonne - 1;
                cells[1][0] = ligne - 1; cells[1][1] = colonne;
                cells[2][0] = ligne; cells[2][1] = colonne;
                cells[3][0] = ligne + 1; cells[3][1] = colonne;
                break;
        }
        return check_cells(map, cells, 4);
    }
    
    if (piece->type == 6) // J
    {
        switch (piece->rotation)
        {
            case 0:
                cells[0][0] = ligne - 1; cells[0][1] = colonne - 1;
                cells[1][0] = ligne; cells[1][1] = colonne - 1;
                cells[2][0] = ligne; cells[2][1] = colonne;
                cells[3][0] = ligne; cells[3][1] = colonne + 1;
                break;
            case 1:
                cells[0][0] = ligne - 1; cells[0][1] = colonne + 1;
                cells[1][0] = ligne - 1; cells[1][1] = colonne;
                cells[2][0] = ligne; cells[2][1] = colonne;
                cells[3][0] = ligne + 1; cells[3][1] = colonne;
                break;
            case 2:
                cells[0][0] = ligne; cells[0][1] = colonne - 1;
                cells[1][0] = ligne; cells[1][1] = colonne;
                cells[2][0] = ligne; cells[2][1] = colonne + 1;
                cells[3][0] = ligne + 1; cells[3][1] = colonne + 1;
                break;
            case 3:
                cells[0][0] = ligne - 1; cells[0][1] = colonne;
                cells[1][0] = ligne; cells[1][1] = colonne;
                cells[2][0] = ligne + 1; cells[2][1] = colonne;
                cells[3][0] = ligne + 1; cells[3][1] = colonne - 1;
                break;
        }
        return check_cells(map, cells, 4);
    }
    
    return 1;
}

int can_move(char **map, Piece *piece, char direction)
{
    Piece temp = *piece;
    
    if (direction == 'l')
        temp.x -= SIZE_SQUARE;
    else if (direction == 'r')
        temp.x += SIZE_SQUARE;
    else if (direction == 'd')
        temp.y += SIZE_SQUARE;
    
    return is_position_valid(map, &temp);
}