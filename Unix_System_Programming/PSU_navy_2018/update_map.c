/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** update_map
*/

#include "navy.h"

/*
Return 0 if a boat is touch
return -1 otherwise
*/
int update_map(char **map, int x, int y)
{
    x--;
    y--;
    if (map[y][x] != '.' && map[y][x] != 'o') {
        map[y][x] = 'x';
        return (0);
    } else {
        map[y][x] = 'o';
        return (-1);
    }
}

int update_adv_map(char **map, int x, int y, int status)
{
    y--;
    if (status == 2) {
        map[y][x] = 'x';
        return (0);
    } else {
        map[y][x] = 'o';
        return (-1);
    }
}
