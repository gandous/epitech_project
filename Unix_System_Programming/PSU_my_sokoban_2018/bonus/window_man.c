/*
** EPITECH PROJECT, 2018
** my sokoban
** File description:
** window function
*/

#include <stdlib.h>
#include "my_sokoban.h"

WINDOW *create_game_win(WINDOW *win, int w, int h)
{
    int bw = w / 2;
    int bh = h / 2;

    win = newwin(h + 2, w + 1, LINES / 2 - bh - 1, COLS / 2 - bw);
    if (win == NULL)
        exit(84);
    return (win);
}

WINDOW *create_win_no_border(WINDOW *win, int w, int h)
{
    int bw = w / 2;
    int bh = h / 2;

    win = newwin(h, w - 1, LINES / 2 - bh - 1, COLS / 2 - bw);
    if (win == NULL)
        exit(84);
    return (win);
}

WINDOW *create_win_no_border_no_y_center(WINDOW *win, int w, int h, int y)
{
    int bw = w / 2;

    win = newwin(h, w - 1, y, COLS / 2 - bw);
    if (win == NULL)
        exit(84);
    return (win);
}