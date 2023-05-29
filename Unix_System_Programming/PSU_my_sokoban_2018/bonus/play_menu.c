/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** start menu
*/

#include "my_sokoban.h"

int gestion_menu_map(bool color)
{
    char **map_name = load_map_name();
    int select;
    int result = 1;
    int select2 = 1;

    select = create_menu(map_name, create_win_size(20, 5));
    if (select > 0) {
        while (select2 == 1) {
            result = game_loop(map_name[select], color);
            select2 = display_end_game(color);
        }
        free_2d_string(map_name);
    }
    gestion_menu_princ(color);
}

void play_menu(bool color)
{
    gestion_menu_map(color);
}