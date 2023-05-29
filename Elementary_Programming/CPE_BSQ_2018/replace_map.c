/*
** EPITECH PROJECT, 2018
** replace map
** File description:
** replace all . of the map with x
*/

#include "bsq.h"

char **replace_map(char **map, square_coord_t *square)
{
    for (int i = 0 ; i < square->size ; i += 1) {
        for (int ii = 0 ; ii < square->size ; ii += 1)
            map[i + square->y][ii + square->x] = 'x';
    }
}
