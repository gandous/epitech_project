/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** function to copy the save map to the current map
*/

#include "my_sokoban.h"

void my_strcpy(char *dest, char *src)
{
    int i;

    for (i = 0 ; src[i] != '\0' && src[i] != '\n' ; i += 1) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

void check_perso(char c, point_t *pos, int x, int y)
{
    if (c == 'P') {
        pos->x = x;
        pos->y = y;
    }
}

void check_box(char c, int *reaming, int x, int y)
{
    if (c == 'X') {
        *reaming += 1;
    }
}

void search_data(char **map, point_t *pos, int *reaming)
{
    for (int i = 0 ; map[i] != NULL ; i += 1) {
        for (int ii = 0 ; map[i][ii] != '\0' ; ii += 1) {
            check_perso(map[i][ii], pos, ii, i);
            check_box(map[i][ii], reaming, ii, i);
        }
    }
}

void copy_map(map_t *data)
{
    for (int i = 0 ; data->save[i] != NULL ; i += 1) {
        my_strcpy(data->map[i], data->save[i]);
    }
    data->reaming = 0;
    search_data(data->save, data->pos, &data->reaming);
}