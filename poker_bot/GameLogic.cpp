#include <iostream>
#include <limits>
#include "includes/GameLogic.hpp"
#include "includes/preflop.hpp"

using namespace std;

int pot = 0;
int player1_chips = 1000;
int player2_chips = 1000;
int isPlayer = 1;
int isBet = 0;
double betAmount = 0;
int oldBet;

int getPlayerChoice() {
    int choice;

    while (true) {
        cout << "1. Se coucher" << endl;
        cout << "2. Miser" << endl;
        if (isBet == 1)
            cout << "3. Relancer\n" << endl;
        if (isBet == 0)
            cout << "3. Passer\n" << endl;
        cout << "Entrez votre choix (1-3): ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nChoix invalide." << endl;
            continue;
        }
        if ((choice < 1 || choice > 3)) {
            cout << "\nChoix invalide. Veuillez entrer un nombre entre 1 et 3.\n" << endl;
            continue;
        }

        return choice;
    }
}

void whatChoice(int& choice) {
    if (choice == 1) {
        cout << "Vous avez choisi de vous coucher." << endl;
        if (isPlayer == 1)
            player2_chips += pot;
        else
            player1_chips += pot;
        pot = 0;
        choice = 0;
    }
    else if (choice == 2) {
        double bet;
        while (true) {
            cout << "Combien voulez-vous miser ? ";
            cin >> bet;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Saisie invalide.\n";
                continue;
            }
            if (bet < oldBet) {
                cout << "Vous devez miser au minimum " << oldBet << " unités\n";
                continue;
            }
            if ((isPlayer == 1 && bet > player1_chips) || (isPlayer == 2 && bet > player2_chips)) {
                cout << "Vous ne pouvez pas miser plus que votre balance\n";
                continue;
            }
            break;
        }
        if ((isPlayer == 1 && bet > player1_chips) || (isPlayer == 2 && bet > player2_chips)) {
        {
            if (isPlayer == 1)
                bet = player2_chips;
            else
                bet = player1_chips;
        }
        cout << "Vous avez misé " << bet << " unités." << endl;
        if (isPlayer == 1)
            player1_chips -= bet;
        else
            player2_chips -= bet;
        pot += bet;
        oldBet = bet;
        isBet = 1;
        choice = 0;
    }
    else if (choice == 3 && isBet == 1) {
        cout << "Vous avez relancé de " << oldBet << " unités." << endl;
        if ((isPlayer == 1 && oldBet > player1_chips) || (isPlayer == 2 && oldBet > player2_chips)) {
            cout << "Vous ne pouvez pas suivre, vous n'avez pas assez de jetons.\n";
            if (isPlayer == 1)
                player2_chips += pot;
            else
                player1_chips += pot;
            pot = 0;
            choice = 0;
            return;
        }

        if (isPlayer == 1)
            player1_chips -= oldBet;
        else
            player2_chips -= oldBet;

        pot += oldBet;
        isBet = 0;
        choice = 0;
    }
    else if (choice == 3 && isBet == 0) {
        cout << "Vous avez choisi de passer." << endl;
        choice = 3;
        isBet = 0;
        }
    }
}

int turnPlayer() {
    int choice, keep_choice;
    cout << "\nTour du Joueur 1" << endl;
    isPlayer = 1;
    choice = getPlayerChoice();
    keep_choice = choice;
    whatChoice(choice);
    if (keep_choice == 1)
    {return 0;}
    messagePoints();
    cout << "\nTour du Joueur 2" << endl;
    isPlayer = 2;
    choice = getPlayerChoice();
    keep_choice = choice;
    whatChoice(choice);
    if (keep_choice == 1) 
        {return 0;}
    return 1;
}