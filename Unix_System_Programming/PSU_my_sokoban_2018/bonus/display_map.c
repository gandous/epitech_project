/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** display map function
*/

#include "my_sokoban.h"
#include "my_color.h"

void displa_char(char *ligne, int *index, int color, WINDOW *box)
{
    char first_char = ligne[*index];

    wattron(box, COLOR_PAIR(color));
    while (ligne[*index] == first_char && ligne[*index] != '\0') {
        wprintw(box, "%c", ligne[*index]);
        *index += 1;
    }
    wattroff(box, COLOR_PAIR(color));
}

void display_ligne(char *ligne, int *index, WINDOW *box)
{
    switch(ligne[*index]) {
    case '#':
        displa_char(ligne, index, PAIR_WALL, box);
        break;
    case 'P':
        displa_char(ligne, index, PAIR_PERSO, box);
        break;
    case 'X':
        displa_char(ligne, index, PAIR_BOX, box);
        break;
    case 'O':
        displa_char(ligne, index, PAIR_HOLL, box);
        break;
    default:
        displa_char(ligne, index, PAIR_GROUND, box);
        break;
    }
}

void choose_display_mode(char **map, WINDOW *box, bool color)
{
    if (color)
        display_color_map(map, box);
    else
        display_map(map, box);
}

void display_color_map(char **map, WINDOW *box)
{
    for (int i = 0 ; map[i] != NULL ; i += 1) {
        wmove(box, i + 1, 1);
        for (int ii = 0 ; map[i][ii] != '\0' ; ) {
            display_ligne(map[i], &ii, box);
        }
    }
}