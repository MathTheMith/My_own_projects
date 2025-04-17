#ifndef GAMELOGIC_HPP
#define GAMELOGIC_HPP

extern int pot;
extern int player1_chips;
extern int player2_chips;
extern int isPlayer;
extern int isBet;
extern double betAmount;
extern int oldBet;
#include <vector>

struct HandStrength {
    int rank; // 10 = Quinte flush royale, 1 = hauteur
    std::vector<int> kickers; // pour départager les égalités
};

int getPlayerChoice();
void whatChoice(int& choice);
int turnPlayer();
void declareWinner();
void messagePoints();
bool tourDeMise();

#endif