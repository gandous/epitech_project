/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** all function to init the color
*/

#include "my_color.h"

bool verif_color(void)
{
    if (has_colors() == true && can_change_color() == true) {
        start_color();
        init_my_pair();
        return (true);
    } else
        return (false);
}

void create_color_rgb(int color_id, float r, float g, float b)
{
    if ((r > 255 || r < 0) && (r > 255 || r < 0) && (r > 255 || r < 0))
        return;
    r = (r / 255) * 1000;
    g = (g / 255) * 1000;
    b = (b / 255) * 1000;
    init_color(color_id, r, g, b);
}

void init_my_pair()
{
    init_pair(PAIR_WALL, COL_WALL, COLOR_BLACK);
    init_pair(PAIR_BOX, COL_BOX, COLOR_BLACK);
    init_pair(PAIR_HOLL, COL_HOLL, COLOR_BLACK);
    init_pair(PAIR_PERSO, COL_PERSO, COLOR_BLACK);
    init_pair(PAIR_GROUND, COL_GROUND, COLOR_BLACK);
    init_pair(PAIR_SOKOBAN, COL_SOKOBAN, COLOR_BLACK);
    create_color_rgb(COL_WALL, 201, 58, 58);
    create_color_rgb(COL_BOX, 211, 189, 58);
    create_color_rgb(COL_HOLL, 96, 201, 92);
    create_color_rgb(COL_PERSO, 52, 148, 226);
    create_color_rgb(COL_GROUND, 0, 0, 0);
    create_color_rgb(COL_SOKOBAN, 255, 132, 67);
}