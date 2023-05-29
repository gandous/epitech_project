/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** detecte when the useer bloc a box
*/

#include "my_sokoban.h"

int check_mur(char **save, char **map, int x, int y)
{
    if (save[y][x] == '#' || map[y][x] == 'X')
        return (1);
    return (0);
}

int check_block_box(char **map, char **save, int x_pos, int y_pos)
{
    int top = 0;
    int bottom = 0;
    int left = 0;
    int right = 0;

    if (save[y_pos][x_pos] == 'O' || map[y_pos][x_pos] != 'X')
        return (0);
    left = check_mur(save, map, x_pos - 1, y_pos);
    right = check_mur(save, map, x_pos + 1, y_pos);
    top = check_mur(save, map, x_pos, y_pos - 1);
    bottom = check_mur(save, map, x_pos, y_pos + 1);
    if (left == 1 && top == 1)
        return (1);
    if (right == 1 && top == 1)
        return (1);
    if (left == 1 && bottom == 1)
        return (1);
    if (right == 1 && bottom == 1)
        return (1);
    return (0);
}

int verif_box_ligne(char **map, char **save, int y)
{
    int bloc_box = 0;

    for (int x = 0 ; map[y][x] != '\0' ; x += 1) {
        if (check_block_box(map, save, x, y) == 1)
            bloc_box += 1;
    }
    return (bloc_box);
}

int box_bloc(char **map, char **save)
{
    int bloc_box = 0;

    for (int i = 0 ; map[i] != NULL ; i += 1)
        bloc_box += verif_box_ligne(map, save, i);
    return (bloc_box);
}
