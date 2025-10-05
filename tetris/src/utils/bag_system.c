#include "utils.h"

static int bag[7] = {0, 1, 2, 3, 4, 5, 6};
static int bag_index = 7;
static int next_bag[7] = {0, 1, 2, 3, 4, 5, 6};
static int next_bag_index = 7;

static void shuffle_bag(void)
{
    for (int i = 6; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = bag[i];
        bag[i] = bag[j];
        bag[j] = temp;
    }
}

void init_bag_system(void)
{
    shuffle_bag();
    bag_index = 0;
    
    // Prépare le prochain sac
    for (int i = 0; i < 7; i++)
        next_bag[i] = i;
    for (int i = 6; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = next_bag[i];
        next_bag[i] = next_bag[j];
        next_bag[j] = temp;
    }
    next_bag_index = 0;
}

int get_next_piece(void)
{
    if (bag_index >= 7)
    {
        // Copie le next_bag dans bag
        for (int i = 0; i < 7; i++)
            bag[i] = next_bag[i];
        bag_index = 0;
        
        // Génère un nouveau next_bag
        for (int i = 0; i < 7; i++)
            next_bag[i] = i;
        for (int i = 6; i > 0; i--)
        {
            int j = rand() % (i + 1);
            int temp = next_bag[i];
            next_bag[i] = next_bag[j];
            next_bag[j] = temp;
        }
        next_bag_index = 0;
    }
    
    return bag[bag_index++];
}

void get_next_queue(int *queue, int count)
{
    int pos = 0;
    int current_bag_idx = bag_index;
    
    // Prend d'abord du sac actuel
    while (pos < count && current_bag_idx < 7)
    {
        queue[pos++] = bag[current_bag_idx++];
    }
    
    // Si besoin, prend du prochain sac
    int next_idx = 0;
    while (pos < count && next_idx < 7)
    {
        queue[pos++] = next_bag[next_idx++];
    }
}