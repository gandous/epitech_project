/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** color header for sokoban
*/

#include <ncurses.h>

#ifndef MY_COLOR_H_
#define MY_COLOR_H_

#define COL_WALL 10
#define COL_BOX 11
#define COL_HOLL 12
#define COL_PERSO 13
#define COL_GROUND 14
#define COL_SOKOBAN 15
#define PAIR_WALL 1
#define PAIR_BOX 2
#define PAIR_HOLL 3
#define PAIR_PERSO 4
#define PAIR_GROUND 5
#define PAIR_SOKOBAN 6

void display_color_map(char **map, WINDOW *box);
void init_my_pair();
bool verif_color(void);
void choose_display_mode(char **map, WINDOW *box, bool color);

#endif
