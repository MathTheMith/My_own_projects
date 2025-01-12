#include "chess_game.h"

bool can_capture(Texture2D board[BOARD_SIZE][BOARD_SIZE], int x, int y, int old_x, int old_y) {
    bool is_selected_white = (board[old_x][old_y].id == wR.id || 
                            board[old_x][old_y].id == wN.id || 
                            board[old_x][old_y].id == wB.id || 
                            board[old_x][old_y].id == wK.id || 
                            board[old_x][old_y].id == wQ.id ||
                            board[old_x][old_y].id == wP.id);

    bool is_target_black = (board[x][y].id == bR.id || 
                          board[x][y].id == bN.id || 
                          board[x][y].id == bB.id || 
                          board[x][y].id == bK.id || 
                          board[x][y].id == bQ.id ||
                          board[x][y].id == bP.id);

    bool is_selected_black = (board[old_x][old_y].id == bR.id || 
                            board[old_x][old_y].id == bN.id || 
                            board[old_x][old_y].id == bB.id || 
                            board[old_x][old_y].id == bK.id || 
                            board[old_x][old_y].id == bQ.id ||
                            board[old_x][old_y].id == bP.id);

    bool is_target_white = (board[x][y].id == wR.id || 
                          board[x][y].id == wN.id || 
                          board[x][y].id == wB.id || 
                          board[x][y].id == wK.id || 
                          board[x][y].id == wQ.id ||
                          board[x][y].id == wP.id);

    if (is_selected_white && is_target_black)
        return true;

    if (is_selected_black && is_target_white)
        return true;

    return false;
}
