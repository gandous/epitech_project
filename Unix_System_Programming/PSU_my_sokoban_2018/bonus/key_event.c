/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** fucn for event
*/

#include <stdlib.h>
#include "my_sokoban.h"

void verif_size(map_t *data, WINDOW *box, int *w_size)
{
    int box_w = COLS / 2 - data->w / 2;
    int box_h = LINES / 2 - data->h / 2 - 1; 

    if (LINES > data->h && COLS > data->w) {
        mvwin(box, box_h, box_w);
        box(box, ACS_VLINE, ACS_HLINE);
        wrefresh(box);
        refresh();
        *w_size = 0;
    } else {
        *w_size = -1;
    }
}

int check_event(int event, map_t *map_data, int *w_size, WINDOW *box)
{
    switch (event) {
    case 65:
        move_player(0, -1, map_data);
        break;
    case 66:
        move_player(0, 1, map_data);
        break;
    case 67:
        move_player(1, 0, map_data);
        break;
    case 68:
        move_player(-1, 0, map_data);
        break;
    case 32:
        copy_map(map_data);
        break;
    case 410:
        verif_size(map_data, box, w_size);
        break;
    }
}