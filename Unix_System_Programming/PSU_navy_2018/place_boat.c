/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** place_boat
*/

#include <stdlib.h>
#include "navy.h"

/* 2:C1:C2
     xy xy
   0123456
*/
static int place_one_boat(char **map, char *buff, int i)
{
    int x_diff = buff[i+2] - buff[i+5];
    int y_diff = buff[i+3] - buff[i+6];

    x_diff < 0 ? x_diff *= -1 : x_diff;
    y_diff < 0 ? y_diff *= -1 : y_diff;
    if (x_diff == 0)
        for (int ind = buff[i+3] - 1 ; ind < buff[i+6] ; ind++)
            map[ind - '0'][buff[i+2] - 'A'] = buff[i];
    else if (y_diff == 0)
        for (int ind = buff[i+2] ; ind < buff[i+5] + 1 ; ind++)
            map[buff[i+3] - '0' - 1][ind - 'A'] = buff[i];
    else
        return (ERROR);
    return (SUCCESS);
}

int place_boat(char **map, char *buffer)
{
    for (int i = 0 ; buffer[i] != '\0' ; i += 1) {
        if (buffer[i + 1] == '\0')
            break;
        place_one_boat(map, buffer, i);
        i += 7;
    }
}
