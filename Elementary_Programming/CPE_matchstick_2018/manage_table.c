/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** generate_table
*/

#include <stdlib.h>
#include "matchstick.h"

char *generate_line(int size, int bar, int index)
{
    char *line = NULL;
    int i = 1;

    line = malloc(sizeof(char) * (size + 1));
    if (line == NULL)
        return (NULL);
    line[0] = '*';
    line[size] = '\0';
    line[size - 1] = '*';
    for ( ; i  < size / 2 - index + 1 ; i += 1)
        line[i] = ' ';
    for (int bar_nb = 0 ; bar_nb < bar ; i += 1, bar_nb += 1)
        line[i] = '|';
    for ( ; i < size - 1 ; i += 1)
        line[i] = ' ';
    return (line);
}

char **generate_table(int size)
{
    char **map = NULL;
    int bar = 1;
    int width = 1 + size * 2;

    if ((map = malloc(sizeof(char *) * (size + 3))) == NULL)
        return (NULL);
    map[size + 2] = NULL;
    map[0] = malloc(sizeof(char) * (width + 1));
    map[size + 1] = malloc(sizeof(char) * (width + 1));
    if (map[0] == NULL || map[size + 1] == NULL)
        return (NULL);
    for (int i = 0 ; i < width ; i += 1) {
        map[0][i] = '*';
        map[size + 1][i] = '*';
    }
    map[0][width] = '\0';
    map[size + 1][width] = '\0';
    for (int i = 1 ; i < size + 1 ; i += 1, bar += 2)
        map[i] = generate_line(width, bar, i);
    return (map);
}

void display_map(char **map)
{
    for (int i = 0 ; map[i] != NULL ; i += 1) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
}

void delete_map(char **map)
{
    for (int i = 0 ; map[i] != NULL ; i += 1)
        free(map[i]);
    free(map);
}