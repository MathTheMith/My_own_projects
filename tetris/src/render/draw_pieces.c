#include "pieces.h"

void draw_cube(int x, int y, Color color)
{
    DrawRectangle(x, y, SIZE_SQUARE, SIZE_SQUARE, color);
    DrawRectangle(x, y, 5, SIZE_SQUARE, GRAY);
    DrawRectangle(x, y, SIZE_SQUARE, 5, GRAY);
    DrawRectangle(x, y + SIZE_SQUARE - 5, SIZE_SQUARE, 5, GRAY);
    DrawRectangle(x + SIZE_SQUARE - 5, y, 5, SIZE_SQUARE, GRAY);
}

static void draw_I(int x, int y, int rotation, Color color)
{
    if (rotation == 0 || rotation == 2)
    {
        draw_cube(x - SIZE_SQUARE * 2, y, color);
        draw_cube(x - SIZE_SQUARE, y, color);
        draw_cube(x, y, color);
        draw_cube(x + SIZE_SQUARE, y, color);
    }
    else
    {
        draw_cube(x, y - SIZE_SQUARE * 2, color);
        draw_cube(x, y - SIZE_SQUARE, color);
        draw_cube(x, y, color);
        draw_cube(x, y + SIZE_SQUARE, color);
    }
}

static void draw_O(int x, int y, Color color)
{
    draw_cube(x - SIZE_SQUARE, y - SIZE_SQUARE, color);
    draw_cube(x, y - SIZE_SQUARE, color);
    draw_cube(x - SIZE_SQUARE, y, color);
    draw_cube(x, y, color);
}

static void draw_T(int x, int y, int rotation, Color color)
{
    switch (rotation)
    {
        case 0:
            draw_cube(x - SIZE_SQUARE, y, color);
            draw_cube(x, y - SIZE_SQUARE, color);
            draw_cube(x, y, color);
            draw_cube(x + SIZE_SQUARE, y, color);
            break;
        case 1:
            draw_cube(x, y - SIZE_SQUARE, color);
            draw_cube(x, y, color);
            draw_cube(x + SIZE_SQUARE, y, color);
            draw_cube(x, y + SIZE_SQUARE, color);
            break;
        case 2:
            draw_cube(x - SIZE_SQUARE, y, color);
            draw_cube(x, y, color);
            draw_cube(x, y + SIZE_SQUARE, color);
            draw_cube(x + SIZE_SQUARE, y, color);
            break;
        case 3:
            draw_cube(x, y - SIZE_SQUARE, color);
            draw_cube(x - SIZE_SQUARE, y, color);
            draw_cube(x, y, color);
            draw_cube(x, y + SIZE_SQUARE, color);
            break;
    }
}

static void draw_S(int x, int y, int rotation, Color color)
{
    if (rotation == 0 || rotation == 2)
    {
        draw_cube(x - SIZE_SQUARE, y, color);
        draw_cube(x, y - SIZE_SQUARE, color);
        draw_cube(x, y, color);
        draw_cube(x + SIZE_SQUARE, y - SIZE_SQUARE, color);
    }
    else
    {
        draw_cube(x, y - SIZE_SQUARE, color);
        draw_cube(x, y, color);
        draw_cube(x + SIZE_SQUARE, y, color);
        draw_cube(x + SIZE_SQUARE, y + SIZE_SQUARE, color);
    }
}

static void draw_Z(int x, int y, int rotation, Color color)
{
    if (rotation == 0 || rotation == 2)
    {
        draw_cube(x - SIZE_SQUARE, y - SIZE_SQUARE, color);
        draw_cube(x, y - SIZE_SQUARE, color);
        draw_cube(x, y, color);
        draw_cube(x + SIZE_SQUARE, y, color);
    }
    else
    {
        draw_cube(x + SIZE_SQUARE, y - SIZE_SQUARE, color);
        draw_cube(x, y, color);
        draw_cube(x + SIZE_SQUARE, y, color);
        draw_cube(x, y + SIZE_SQUARE, color);
    }
}

static void draw_L(int x, int y, int rotation, Color color)
{
    switch (rotation)
    {
        case 0:
            draw_cube(x - SIZE_SQUARE, y, color);
            draw_cube(x, y, color);
            draw_cube(x + SIZE_SQUARE, y, color);
            draw_cube(x + SIZE_SQUARE, y - SIZE_SQUARE, color);
            break;
        case 1:
            draw_cube(x, y - SIZE_SQUARE, color);
            draw_cube(x, y, color);
            draw_cube(x, y + SIZE_SQUARE, color);
            draw_cube(x + SIZE_SQUARE, y + SIZE_SQUARE, color);
            break;
        case 2:
            draw_cube(x - SIZE_SQUARE, y, color);
            draw_cube(x, y, color);
            draw_cube(x + SIZE_SQUARE, y, color);
            draw_cube(x - SIZE_SQUARE, y + SIZE_SQUARE, color);
            break;
        case 3:
            draw_cube(x - SIZE_SQUARE, y - SIZE_SQUARE, color);
            draw_cube(x, y - SIZE_SQUARE, color);
            draw_cube(x, y, color);
            draw_cube(x, y + SIZE_SQUARE, color);
            break;
    }
}

static void draw_J(int x, int y, int rotation, Color color)
{
    switch (rotation)
    {
        case 0:
            draw_cube(x - SIZE_SQUARE, y - SIZE_SQUARE, color);
            draw_cube(x - SIZE_SQUARE, y, color);
            draw_cube(x, y, color);
            draw_cube(x + SIZE_SQUARE, y, color);
            break;
        case 1:
            draw_cube(x + SIZE_SQUARE, y - SIZE_SQUARE, color);
            draw_cube(x, y - SIZE_SQUARE, color);
            draw_cube(x, y, color);
            draw_cube(x, y + SIZE_SQUARE, color);
            break;
        case 2:
            draw_cube(x - SIZE_SQUARE, y, color);
            draw_cube(x, y, color);
            draw_cube(x + SIZE_SQUARE, y, color);
            draw_cube(x + SIZE_SQUARE, y + SIZE_SQUARE, color);
            break;
        case 3:
            draw_cube(x, y - SIZE_SQUARE, color);
            draw_cube(x, y, color);
            draw_cube(x, y + SIZE_SQUARE, color);
            draw_cube(x - SIZE_SQUARE, y + SIZE_SQUARE, color);
            break;
    }
}

void draw_piece(Piece *piece)
{
    Color colors[7] = {
        (Color){150, 201, 255, 255}, // I - cyan
        YELLOW,                       // O
        VIOLET,                       // T
        GREEN,                        // S
        RED,                          // Z
        ORANGE,                       // L
        BLUE                          // J
    };
    
    typedef void (*DrawFunc)(int, int, int, Color);
    DrawFunc funcs[7] = {draw_I, NULL, draw_T, draw_S, draw_Z, draw_L, draw_J};
    
    if (piece->type == 1)
        draw_O(piece->x, piece->y, colors[1]);
    else if (piece->type >= 0 && piece->type < 7)
        funcs[piece->type](piece->x, piece->y, piece->rotation, colors[piece->type]);
}

void draw_piece_preview(int type, int x, int y)
{
    Piece preview = {type, x, y, 0};
    draw_piece(&preview);
}