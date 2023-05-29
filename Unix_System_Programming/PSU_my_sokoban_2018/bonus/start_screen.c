/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** all function to generate start screen
*/

#include "my_sokoban.h"
#include "my_color.h"

void display_start_screen(bool color)
{
    WINDOW *win = create_win_no_border(win, 50, 7);

    if (color)
        wattron(win, COLOR_PAIR(PAIR_SOKOBAN));
    mvwprintw(win, 0, 0, "   _____         _           _                   ");
    mvwprintw(win, 1, 0, "  / ____|       | |         | |                  ");
    mvwprintw(win, 2, 0, " | (___    ___  | | __ ___  | |__    __ _  _ __  ");
    mvwprintw(win, 3, 0, "  \\___ \\  / _ \\ | |/ // _ \\ | '_ \\  / _` || '_ \\ ");
    mvwprintw(win, 4, 0, "  ____) || (_) ||   <| (_) || |_) || (_| || | | |");
    mvwprintw(win, 5, 0, " |_____/  \\___/ |_|\\_\\\\___/ |_.__/  \\__,_||_| |_|");
    mvwprintw(win, 6, 0, "            Press any key to start               ");
    if (color)
        wattroff(win, COLOR_PAIR(PAIR_SOKOBAN));
    refresh();
    wrefresh(win);
    getch();
    delwin(win);
    clear();
    refresh();
}