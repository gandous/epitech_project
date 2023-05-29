/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** gameloop
*/

#include <stdlib.h>
#include "navy.h"

static int my_turn_status(int status)
{
    if (status == ERROR)
        return (ERROR);
    if (status == WIN) {
        mputstr("I won\n");
        return (0);
    }
}

static int advers_turn_status(int status)
{
    if (status == ERROR)
        return (ERROR);
    if (status == WIN) {
        mputstr("Ennemy won\n");
        return (1);
    }
}

int player_one_loop(pid_t pid_usr, char **map)
{
    char **adv_map = generate_adv_map();
    int status = 0;

    set_sigaction();
    print_game(map, adv_map);
    while (1) {
        status = play_my_turn(pid_usr, map, adv_map);
        if (status == ERROR || status == WIN)
            return (my_turn_status(status));
        status = play_advers_turn(pid_usr, map, adv_map);
        if (status == ERROR || status == WIN)
            return (advers_turn_status(status));
        print_game(map, adv_map);
    }
}

int player_two_loop(pid_t pid_usr, char **map)
{
    char **adv_map = generate_adv_map();
    int status = 0;

    set_sigaction();
    print_game(map, adv_map);
    while (1) {
        status = play_advers_turn(pid_usr, map, adv_map);
        if (status == ERROR || status == WIN)
            return (advers_turn_status(status));
        status = play_my_turn(pid_usr, map, adv_map);
        if (status == ERROR || status == WIN)
            return (my_turn_status(status));
        print_game(map, adv_map);
    }
}
