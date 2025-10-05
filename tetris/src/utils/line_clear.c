#include "utils.h"

static int is_line_full(char **map, int line)
{
    for (int j = 0; j < MAP_WIDTH; j++)
        if (map[line][j] == 0)
            return 0;
    return 1;
}

static void clear_line(char **map, int line)
{
    for (int i = line; i > 0; i--)
        for (int j = 0; j < MAP_WIDTH; j++)
            map[i][j] = map[i - 1][j];
    
    for (int j = 0; j < MAP_WIDTH; j++)
        map[0][j] = 0;
}

int check_and_clear_lines(char **map)
{
    int lines_cleared = 0;
    
    for (int i = MAP_HEIGHT - 1; i >= 0; i--)
    {
        if (is_line_full(map, i))
        {
            clear_line(map, i);
            lines_cleared++;
            i++;
        }
    }
    
    return lines_cleared;
}