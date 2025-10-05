#include "chess_game.h"

void init_board(Texture2D board[BOARD_SIZE][BOARD_SIZE])
{
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
}