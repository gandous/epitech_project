/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** test display in terminal
*/

#include <stdlib.h>
#include "my_sokoban.h"

int main(int argc, char **argv)
{
    if (argc > 1) {
        if (argv[1][0] == '-' && argv[1][1]== 'h')
            display_usage();
        else
            my_sokoban(argv[1]);
    } else
        game_menu();
    return (0);
}