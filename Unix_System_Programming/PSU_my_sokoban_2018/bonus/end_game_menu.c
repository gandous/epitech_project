/*
** EPITECH PROJECT, 2018
** bonus
** File description:
** display the end game menu
*/

#include "my_sokoban.h"

int display_end_game(bool color)
{
    char *choose[11] = {"you win :)", "menu", "replay", NULL};

    return (create_popup(choose, create_win_size(30, 2)));
}