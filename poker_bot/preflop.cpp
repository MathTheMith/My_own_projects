#include <iostream>
#include <limits>
#include "includes/preflop.hpp"
#include "includes/GameLogic.hpp"

using namespace std;

void Bind() {
    cout << "\nPlayer 1, small blind 10 chips" << endl;
    cout << "Player 2, big blind 20 chips" << endl;
    player1_chips -= 10;
    player2_chips -= 20;
    pot = 30;
}

void messagePoints()
{
    cout << "\n------------------------" << endl;
    cout <<"Pot : " << pot << " pieces" << endl;
    cout << "------------------------" << endl;
    cout <<"Player 1 : " << player1_chips << " pieces" << endl;
    cout << "------------------------" << endl;
    cout <<"Player 2 : " << player2_chips << " pieces" << endl;
    cout << "------------------------" << endl;
}
int getFirstChoice() {
    int choice;

    while (true) {
        cout << "Choisissez une action après avoir reçu vos cartes:\n" << endl;
        cout << "1. Relancer" << endl;
        cout << "2. Se coucher" << endl;
        cout << "3. Miser\n" << endl;
        cout << "Entrez votre choix (1-3): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nChoix invalide." << endl;
            continue;
        }
        if (choice < 1 || choice > 3) {
            cout << "\nChoix invalide. Veuillez entrer un nombre entre 1 et 3.\n" << endl;
            continue;
        }
        return choice;
    }
}

void whatFirstChoice(int& choice) {
    double betAmount;

    if (choice == 1) {
        cout << "Vous avez relancé de 20 unités." << endl;
        player1_chips -= 20;
        pot += 20;
        choice = 0;
    }
    else if (choice == 2) {
        cout << "Vous avez choisi de vous coucher." << endl;
        player2_chips += pot;
        choice = 0;
    }
    else if (choice == 3) {
        while (true) {
            cout << "Combien voulez-vous miser (minimum 40) ? ";
            cin >> betAmount;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Saisie invalide.\n";
                continue;
            }
            if (betAmount < 40) {
                cout << "Vous devez miser au minimum 40 unités\n";
                continue;
            }
            if ((isPlayer == 1 && betAmount > player1_chips) || 
                (isPlayer == 2 && betAmount > player2_chips)) {
                cout << "Vous ne pouvez pas miser plus que votre balance\n";
                continue;
            }
            break;
        }
        cout << "Vous avez misé " << betAmount << " unités." << endl;
        if (isPlayer == 1)
            player1_chips -= betAmount;
        else if (isPlayer == 2)
            player2_chips -= betAmount;

        pot += betAmount;
        oldBet = betAmount;
        isBet = 1;
        choice = 0;
    }
}

int turnFirstPlayer() {
    int choice, keep_choice;
    cout << "\nTour du Joueur 1" << endl;
    choice = getFirstChoice();
    keep_choice = choice;
    whatFirstChoice(choice);
    if (keep_choice == 2) {
        return 0;
    }
    cout << "\nTour du Joueur 2" << endl;
    isPlayer = 2;
    choice = getPlayerChoice();
    keep_choice = choice;
    whatChoice(choice);
    if (keep_choice == 1)
        return 0;
    return (1);
}