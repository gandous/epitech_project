/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** player_manager
*/

#include <stdio.h>
#include <stdlib.h>
#include "matchstick.h"

int recup_number(char *info)
{
    char *buff = NULL;
    size_t len = 0;
    int nb = -1;

    while (nb < 0) {
        my_putstr(info);
        if (getline(&buff, &len, stdin) == -1)
            return (-1);
        if (is_number(buff) == -1)
            return (-2);
        else
            nb = my_getnbr(buff);
    }
    free(buff);
    return (nb);
}

int recup_line(int size)
{
    int line = -2;

    while ((line <= 0 || line > size) && line != -1) {
        line = recup_number("Line: ");
        if (line == 0 || line > size)
            my_putstr("Error: this line is out of range\n");
        else if (line == -2)
            my_putstr("Error: invalid input (positive number expected)\n");
    }
    return (line);
}

int recup_matches(int max_stick)
{
    int stick = -2;

    while ((stick <= 0 || stick > max_stick) && stick != -1) {
        stick = recup_number("Matches: ");
        if (stick == 0) {
            my_putstr("Error: you have to remove at least one match\n");
            return (-2);
        } else if (stick > max_stick) {
            my_putstr("Error: you cannot remove more than ");
            my_put_nbr(max_stick);
            my_putstr(" matches per turn\n");
            return (-2);
        } else if (stick == -2) {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (-2);
        }
    }
    return (stick);
}

void display_player(int line, int stick)
{
    my_putstr("Player removed ");
    my_put_nbr(stick);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

int player_manager(char **map, int size, int max_stick)
{
    int line = -2;
    int stick = -2;

    my_putstr("\nYour turn:\n");
    while (stick <= -2 || line <= -2) {
        line = recup_line(size);
        if (line == -1)
            return (-1);
        stick = recup_matches(max_stick);
        if (stick == -1)
            return (-1);
        if (verif_sitck(map[line], stick) == 0 && stick > 0) {
            my_putstr("Error: not enough matches on this line\n");
            stick = -2;
        }
    }
    display_player(line, stick);
    remove_stick(map[line], stick);
    return (0);
}