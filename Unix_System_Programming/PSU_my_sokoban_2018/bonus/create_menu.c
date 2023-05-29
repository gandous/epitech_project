/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** all function to create a menu
*/

#include "my_sokoban.h"

win_size_t create_win_size(int w, int h)
{
    win_size_t size;
    size.w = w;
    size.h = h;
    return (size);
}

void detecte_event(char **content, int *highlight, int key) {
    switch (key) {
    case 65:
        if (*highlight > 0)
            *highlight -= 1;
        break;
    case 66:
        if (content[*highlight + 1] != NULL)
            *highlight += 1;
        break;
    default:
        break;
    }
}

void display_menu_line(char *line, win_size_t size, WINDOW *win, bool reverse)
{
    int lenght = my_strlen(line);
    if (lenght > size.w)
        return;
    int x_pos = size.w / 2 - lenght / 2;
    if (reverse)
        wattron(win, A_REVERSE);
    mvwprintw(win, size.h + 1, x_pos, line);
    if (reverse)
        wattroff(win, A_REVERSE);
}

void display_menu(char **content, WINDOW *win, int highlight, win_size_t size)
{
    int i;
    int y_pos = 0;

    for (i = highlight  - 2 ; i < 0 ; i += 1, y_pos += 1);
    for ( ; i <= highlight + 2  && content[i] != NULL ; i += 1, y_pos += 1) {
        size.h = y_pos;
        if (i == highlight)
            display_menu_line(content[i], size, win, true);
        else
            display_menu_line(content[i], size, win, false);
    }
    box(win, ACS_VLINE, ACS_HLINE);
    refresh();
    wrefresh(win);
}

int create_menu(char **content, win_size_t size)
{
    WINDOW *win = create_game_win(win, size.w, size.h);
    int key = 0;
    int highlight = 0;

    refresh();
    display_menu(content, win, highlight, size);
    while (key != 10 && key != 32) {
        key = getch();
        detecte_event(content, &highlight, key);
        wclear(win);
        display_menu(content, win, highlight, size);
    }
    delwin(win);
    clear();
    refresh();
    return (highlight);
}