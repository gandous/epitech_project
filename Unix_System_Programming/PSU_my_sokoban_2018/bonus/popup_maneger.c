/*
** EPITECH PROJECT, 2018
** bonus
** File description:
** popup maneger function which display a dual choise
*/

#include "my_sokoban.h"

void key_event(int *highlight, int key)
{
    switch (key) {
    case 68:
        if (*highlight > 0)
            *highlight -= 1;
        break;
    case 67:
        if (*highlight < 1)
            *highlight += 1;
        break;
    }
}

void display_popup(char **txt, WINDOW *win, int highlight, win_size_t size)
{
    clear();
    mvwprintw(win, 1, size.w / 2 - my_strlen(txt[0]) / 2 , txt[0]);
    if (highlight == 0)
        wattron(win, A_REVERSE);
    mvwprintw(win, 2, size.w / 4 - my_strlen(txt[1]) / 2, txt[1]);
    if (highlight == 0)
        wattroff(win, A_REVERSE);
    if (highlight == 1)
        wattron(win, A_REVERSE);
    mvwprintw(win, 2, size.w * 3 / 4 - my_strlen(txt[2]) / 2, txt[2]);
    if (highlight == 1)
        wattroff(win, A_REVERSE);
    box(win, ACS_VLINE, ACS_HLINE);
    refresh();
    wrefresh(win);
}

int create_popup(char **txt, win_size_t size)
{
    WINDOW *win = create_game_win(win, size.w, size.h);
    int highlight = 0;
    int key = 0;

    display_popup(txt, win, highlight, size);
    while (key != 10 && key != 32) {
        key = getch();
        key_event(&highlight, key);
        display_popup(txt, win, highlight, size);
    }
    delwin(win);
    clear();
    refresh();
    return (highlight);
}