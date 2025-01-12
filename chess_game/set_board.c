#include "raylib.h"
#include "chess_game.h"

#define BOARD_SIZE 10

Texture2D wR, bR, wN, bN, wB, bB, wK, bK, wQ, bQ, wP, bP;

bool is_piece_on_square(Texture2D board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    return board[x][y].id != 0;
}

void set_board() {
    Color lightBrown = (Color){181, 135, 99, 255};
    Color lightBeige = (Color){240, 218, 181, 255};
    Color lightBlack = (Color){22, 21, 17, 220};

    wP = LoadTexture("./Images/wP.png");
    bP = LoadTexture("./Images/bP.png");
    wR = LoadTexture("./Images/wR.png");
    bR = LoadTexture("./Images/bR.png");
    wN = LoadTexture("./Images/wN.png");
    bN = LoadTexture("./Images/bN.png");
    wB = LoadTexture("./Images/wB.png");
    bB = LoadTexture("./Images/bB.png");
    wK = LoadTexture("./Images/wK.png");
    bK = LoadTexture("./Images/bK.png");
    wQ = LoadTexture("./Images/wQ.png");
    bQ = LoadTexture("./Images/bQ.png");

    Texture2D board[BOARD_SIZE][BOARD_SIZE] = {0};
    
    board[1][8] = wR; board[8][8] = wR;
    board[2][8] = wN; board[7][8] = wN;
    board[3][8] = wB; board[6][8] = wB;
    board[4][8] = wK; board[5][8] = wQ;

    board[1][1] = bR; board[8][1] = bR;
    board[2][1] = bN; board[7][1] = bN;
    board[3][1] = bB; board[6][1] = bB;
    board[4][1] = bK; board[5][1] = bQ;

    int i = 1;
    while (i < 9) {
        board[i][7] = wP;
        i++;
    }
    
    int j = 1;
    while (j < 9) {
        board[j][2] = bP;
        j++;
    }

    int is_piece = 0;
    int old_x;
    int old_y;
    Texture2D current_piece = {0};

    while (!WindowShouldClose()) {
        Vector2 mousePos = GetMousePosition();
        int x = mousePos.x / 100;
        int y = mousePos.y / 100;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        SetTargetFPS(60);

        int i = 0;
        while (i < BOARD_SIZE) {
            int j = 0;
            while (j < BOARD_SIZE) {
                Color color = ((i + j) % 2 == 0) ? lightBrown : lightBeige;
                if (i == 0 || j == 0 || i == 9 || j == 9) {
                    DrawRectangle(i * 100, j * 100, 100, 100, lightBlack);
                } else {
                    DrawRectangle(i * 100, j * 100, 100, 100, color);
                }
                if (is_piece_on_square(board, i, j)) {
                    DrawTexture(board[i][j], i * 100, j * 100, WHITE);
                }
                j++;
            }
            i++;
        }
        if (is_piece == 1) {
            show_possibles_moves(board, old_x, old_y);
        }
        if (is_piece_on_square(board, x, y) && CheckCollisionPointRec(mousePos, (Rectangle){x * 100, y * 100, 100, 100}) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (is_piece == 0) {
                old_x = x;
                old_y = y;
                current_piece = board[x][y];
                is_piece = 1;
                show_possibles_moves(board, x, y);
            }
            if (is_piece == 1 && can_capture(board, x, y, old_x, old_y)) {
                board[x][y] = current_piece;
                board[old_x][old_y] = (Texture2D){0};
                is_piece = 0;
            }
        }

        if (is_piece == 1 && !is_piece_on_square(board, x, y) && CheckCollisionPointRec(mousePos, (Rectangle){x * 100, y * 100, 100, 100}) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            board[x][y] = current_piece;
            board[old_x][old_y] = (Texture2D){0};
            is_piece = 0;
        }

        EndDrawing();
    }

    UnloadTexture(wP);
    UnloadTexture(bP);
    UnloadTexture(wR);
    UnloadTexture(bR);
    UnloadTexture(wN);
    UnloadTexture(bN);
    UnloadTexture(wB);
    UnloadTexture(bB);
    UnloadTexture(wK);
    UnloadTexture(bK);
    UnloadTexture(wQ);
    UnloadTexture(bQ);
}
