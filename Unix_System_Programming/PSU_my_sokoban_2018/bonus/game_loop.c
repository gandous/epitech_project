/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** game loop function
*/

#include "my_sokoban.h"
#include "load_file.h"
#include "my_color.h"

void display(WINDOW *box, map_t *data, int w_size, bool color)
{
    clear();
    if (w_size == 0)
            choose_display_mode(data->map, box, color);
    else
        display_center("Too small!");
    box(box, ACS_VLINE, ACS_HLINE);
    refresh();
    wrefresh(box);
}

int game_loop(char *filepath, bool color)
{
    int key = 0;
    int w_size = 0;
    map_t *data = load_file(filepath);
    WINDOW *box = create_game_win(box, data->w, data->h);

    choose_display_mode(data->map, box, color);
    refresh();
    box(box, ACS_VLINE, ACS_HLINE);
    wrefresh(box);
    while (key != 113 && data->reaming != 0) {
        key = getch();
        check_event(key, data, &w_size, box);
        display(box, data, w_size, color);
        if (box_bloc(data->map, data->save) == data->reaming)
            break;
    }
    delwin(box);
    map_data_free(data);
    return (data->reaming);
}