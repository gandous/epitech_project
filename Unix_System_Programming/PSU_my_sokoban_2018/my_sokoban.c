/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** main function for sokoban
*/

#include <stdlib.h>
#include "my_sokoban.h"
#include "load_file.h"

int game_loop(map_t *data, WINDOW *box)
{
    int key = 0;
    int w_size = 0;

    while (key != 113 && data->reaming != 0) {
        key = getch();
        clear();
        check_event(key, data, &w_size, box);
        if (w_size == 0)
            display_map(data->map, box);
        else {
            display_center("Too small!");
        }
        if (box_bloc(data->map, data->save) == data->reaming)
            break;
        refresh();
        wrefresh(box);
    }
    return (data->reaming);
}

int my_sokoban(char *filepath)
{
    map_t *data = load_file(filepath);
    WINDOW *win = NULL;
    int bw = data->w / 2;
    int bh = data->h / 2;
    int result;

    initscr();
    win = newwin(data->h, data->w - 1, LINES / 2 - bh, COLS / 2 - bw);
    refresh();
    noecho();
    curs_set(0);
    display_map(data->map, win);
    wrefresh(win);
    result = game_loop(data, win);
    map_data_free(data);
    delwin(win);
    endwin();
    if (result == 0)
        exit(0);
    else
        exit(1);
}
