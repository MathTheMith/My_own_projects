#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char tableau[MAX_LENGTH][10];  // Tableau pour stocker des chaînes de caractères (ici de taille 10 max pour chaque entrée)
    int i = 0;

    // Remplir le tableau avec des lettres colorées
    strcpy(tableau[i++], "\033[32ma\033[0m");  // Lettre 'a' en vert
    strcpy(tableau[i++], "\033[33mb\033[0m");  // Lettre 'b' en jaune
    strcpy(tableau[i++], "\033[31mc\033[0m");  // Lettre 'c' en rouge
    strcpy(tableau[i++], "\033[34md\033[0m");  // Lettre 'd' en bleu

    // Affichage du tableau de lettres colorées
    for (int j = 0; j < i; j++) {
        printf("%s ", tableau[j]);
    }
    printf("\n");

    return 0;
}
