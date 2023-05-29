/*
** EPITECH PROJECT, 2018
** display map
** File description:
** display the 2d array given as arguments
*/

#include "bsq.h"

void display_map(char **map, file_size_t *size)
{
    if (size->height == 1)
        size->width -= 1;
    for (int i = 0 ; i < size->height ; i += 1) {
        my_putstr(map[i], size->width);
        my_putchar('\n');
    }
}
