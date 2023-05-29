/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** main function for sokoban
*/

#include <stdlib.h>
#include "my_sokoban.h"
#include "my_color.h"

int my_sokoban(char *filepath)
{
    WINDOW *win = NULL;
    int result;
    bool color;

    initscr();
    refresh();
    noecho(); 
    curs_set(0);
    color = verif_color();
    result = game_loop(filepath, color);
    endwin();
    if (result == 0)
        exit(0);
    else
        exit(1);
}