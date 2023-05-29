/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** add function to display the menu
*/

#include "my_sokoban.h"
#include "my_color.h"

void display_name(WINDOW *win, bool color)
{
    char *str = "use up and down arrow to navigate and enter to select";

    if (color)
        wattron(win, COLOR_PAIR(PAIR_SOKOBAN));
    mvwprintw(win, 0, 0, " _______  _______  _        _______  ______   _______  _       ");
    mvwprintw(win, 1, 0, "(  ____ \\(  ___  )| \\    /\\(  ___  )(  ___ \\ (  ___  )( (    /|");
    mvwprintw(win, 2, 0, "| (    \\/| (   ) ||  \\  / /| (   ) || (   ) )| (   ) ||  \\  ( |");
    mvwprintw(win, 3, 0, "| (_____ | |   | ||  (_/ / | |   | || (__/ / | (___) ||   \\ | |");
    mvwprintw(win, 4, 0, "(_____  )| |   | ||   _ (  | |   | ||  __ (  |  ___  || (\\ \\) |");
    mvwprintw(win, 5, 0, "      ) || |   | ||  ( \\ \\ | |   | || (  \\ \\ | (   ) || | \\   |");
    mvwprintw(win, 6, 0, "/\\____) || (___) ||  /  \\ \\| (___) || )___) )| )   ( || )  \\  |");
    mvwprintw(win, 7, 0, "\\_______)(_______)|_/    \\/(_______)|/ \\___/ |/     \\||/    )_)");
    if (color)
        wattroff(win, COLOR_PAIR(PAIR_SOKOBAN));
    mvprintw(20, COLS / 2 - my_strlen(str) / 2, str);
    refresh();
    wrefresh(win);
}

int gestion_menu_princ(bool color)
{
    char *menu[] = {"Start", "Editor", "Credits", "Quit", NULL};
    int select;
    WINDOW *win = create_win_no_border_no_y_center(win, 64, 8, 5);

    display_name(win, color);
    select = create_menu(menu, create_win_size(20, 5));
    clear();
    delwin(win);
    refresh();
    switch (select) {
        case 0:
            play_menu(color);
            break;
        case 1:
            gestion_menu_princ(color);
            break;
        case 2:
            gestion_menu_princ(color);
            break;
        case 3:
            return (1);
    }
}

void game_menu(void)
{
    bool color;

    initscr();
    refresh();
    noecho(); 
    curs_set(0);
    color = verif_color();
    display_start_screen(color);
    gestion_menu_princ(color);
    endwin();
}