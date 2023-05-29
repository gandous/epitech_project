/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** verif_win
*/

#include "navy.h"

static int verif_one_line(char *line)
{
    for (int i = 0 ; line[i] != '\0' ; i += 1)
        if (line[i] != '.' && line[i] != 'o' && line[i] != 'x')
            return (0);
    return (WIN);
}

/*
Verif if all boat are destroy
*/
int verif_win(char **map)
{
    for (int i = 0 ; map[i] ; i += 1)
        if (verif_one_line(map[i]) == 0)
            return (0);
    return (WIN);
}