/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** print
*/

#include "navy.h"

int print_game(char **my_map, char **adv_map)
{
    mputstr("my positions:\n");
    print_map(my_map);
    mputstr("enemy's positions:\n");
    print_map(adv_map);
    return (SUCCESS);
}

static void print_map1(char *map)
{
    for (int ii = 0 ; map[ii] != '\0' ; ii += 1) {
        mputchar(map[ii]);
        if (ii < 7)
            mputchar(' ');
    }
}

int print_map(char **map)
{
    mputstr(" |A B C D E F G H\n");
    mputstr("-+---------------\n");
    for (int i = 0 ; map[i] ; i += 1) {
        mputnbr(i + 1);
        mputchar('|');
        print_map1(map[i]);
        mputchar('\n');
    }
    mputchar('\n');
    return (SUCCESS);
}
