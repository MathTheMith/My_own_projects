#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 22735
#define BUFFER_SIZE 30
#define MAX_TRIES 6
#define MAX_WORD_LENGTH 30
#define COLOR_LENGTH 20

typedef struct {
    char colored_word[MAX_WORD_LENGTH][COLOR_LENGTH];
    int word_length;
} Try;

char *get_random_line(const char *filename, int target_line)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Erreur à l'ouverture du fichier");
        return NULL;
    }
    char buffer[BUFFER_SIZE];
    int bytes_read, current_line = 1, buffer_pos = 0, i = 0;
    char *line = malloc(BUFFER_SIZE);
    if (!line) {
        perror("Erreur d'allocation mémoire");
        close(fd);
        return NULL;
    }

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        for (i = 0; i < bytes_read; i++) {
            if (buffer[i] == '\n') {
                buffer[i] = '\0';
                if (current_line == target_line) {
                    strcpy(line, &buffer[buffer_pos]);
                    close(fd);
                    return line;
                }
                current_line++;
                buffer_pos = i + 1;
            }
        }
    }

    close(fd);
    free(line);
    return NULL;
}
char *print_answer(char *word_to_find, char *guess, Try history[], int current_try)
{
    int i = 0;
    int len = strlen(word_to_find);
    char temp[COLOR_LENGTH];
    int used_target[MAX_WORD_LENGTH] = {0};

    history[current_try].word_length = len;

    while (i < len)
    {
        if (guess[i] == word_to_find[i])
        {
            sprintf(temp, "\033[32m%c\033[0m", guess[i]);  // Vert
            strcpy(history[current_try].colored_word[i], temp);
            used_target[i] = 1;
        }
        else
        {
            int found = 0;
            int j = 0;
            while (j < len)
            {
                if (!used_target[j] && guess[i] == word_to_find[j])
                {
                    sprintf(temp, "\033[33m%c\033[0m", guess[i]);  // Jaune
                    strcpy(history[current_try].colored_word[i], temp);
                    used_target[j] = 1;
                    found = 1;
                    break;
                }
                j++;
            }
            if (!found)
            {
                sprintf(temp, "\033[31m%c\033[0m", guess[i]);  // Rouge
                strcpy(history[current_try].colored_word[i], temp);
            }
        }
        i++;
    }
    
    int k = 0;
    while (k <= current_try)
    {
        i = 0;
        while (i < history[k].word_length)
        {
            printf("%s", history[k].colored_word[i]);
            i++;
        }
        printf("\n");
        k++;
    }
    return NULL;
}

void wordle(char *word_to_find)
{
    char guess[MAX_WORD_LENGTH];
    int tries = MAX_TRIES;
    int current_try = 0;
    Try history[MAX_TRIES];

    printf("BIENVENUE AU WORDLE \nQuel est votre premier mot ? \nLe mot est de %ld caractères et vous avez %d essais.\n", 
           strlen(word_to_find), tries);

    while (tries > 0)
    {
        printf("Entrez un mot : ");
        scanf("%s", guess);

        if (strlen(guess) != strlen(word_to_find))
        {
            printf("Il n'y a pas %ld caractères\n", strlen(word_to_find));
            continue;
        }
        print_answer(word_to_find, guess, history, current_try);
        if (strcmp(guess, word_to_find) == 0)
        {
            printf("Félicitations! Vous avez trouvé le mot : %s\n", word_to_find);
            break;
        }
        tries--;
        current_try++;
        
        if (tries > 0)
            printf("Ce n'est pas le bon mot. Il vous reste %d essais\n", tries);
    }
    if (tries == 0)
    {
        printf("Vous avez perdu, le mot était %s\n", word_to_find);
    }
}
int main()
{
    char *word_to_find;
    const char *filename = "liste_mots.txt";
    srand(time(NULL));
    int random_line = rand() % MAX_LINE_LENGTH + 1;

    word_to_find = get_random_line(filename, random_line);
    if (word_to_find == NULL) {
        printf("Erreur : ligne non trouvée.\n");
        return EXIT_FAILURE;
    }
    wordle(word_to_find);
    free(word_to_find);

    return EXIT_SUCCESS;
}
