#include "raylib.h"
#include "chess_game.h"

int main() {
    const int screenWidth = 1000;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Jeu d'échecs");

    set_board();
    CloseWindow();
    return 0;
}
