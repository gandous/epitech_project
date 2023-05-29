/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** matchstick
*/

#include <stdlib.h>
#include "matchstick.h"

int display_end_game(int turn)
{
    if (turn == 0) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    } else if (turn == 1) {
        my_putstr("You lost, too bad...\n");
        return (2);
    }
    return (0);
}

int arg_to_nb(char *str)
{
    if (is_number(str) == -1)
        return (-1);
    return (my_getnbr(str));
}

int matchstick(int argc, char **argv)
{
    int max_stick = arg_to_nb(argv[2]);
    int max_line = arg_to_nb(argv[1]);
    char **map = generate_table(max_line);
    int turn = 0;

    if (max_line <= 1 || max_line >= 100 || max_stick <= 0)
        return (84);
    while (count_reaming_stick(map) > 0) {
        display_map(map);
        if (turn == 0) {
            if (player_manager(map, max_line, max_stick) == -1)
                return (0);
            turn = 1;
        } else {
            ia_manager(map, max_line, max_stick);
            turn = 0;
        }
    }
    display_map(map);
    delete_map(map);
    return (display_end_game(turn));
}