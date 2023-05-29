/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** display function
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_sokoban.h"

void display_map(char **map, WINDOW *box)
{
    for (int i = 0 ; map[i] != NULL ; i += 1) {
        mvwprintw(box, i + 1, 1,"%s", map[i]);
    }
}

int my_strlen(char *str)
{
    int i;

    for ( i = 0 ; str[i] != 0 ; i += 1);
    return (i);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

void display_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban [map]\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map : Launch the map given directly");
    my_putstr("     map file representing the warehouse map, ");
    my_putstr("containing ‘#’ for walls,\n");
    my_putstr("\t ‘P’ for the player, ‘X’ for boxes and");
    my_putstr(" ‘O’ for storage locations.\n");
}

void display_center(char *str)
{
    int x_pos = COLS / 2 - my_strlen(str) / 2;
    mvprintw(LINES / 2, x_pos, str);
}