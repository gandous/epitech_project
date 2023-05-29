/*
** EPITECH PROJECT, 2018
** my_sokoban.c
** File description:
** move the player in the good direction
*/

#include "my_sokoban.h"

void  compare_map(map_t *data, point_t *pos)
{
    if (data->save[pos->y][pos->x] == 'O') {
        data->map[pos->y][pos->x] = 'O';
    } else {
        data->map[pos->y][pos->x] = ' ';
    }
}

void move_box(map_t *data, int tmp_x, int tmp_y, point_t *pos)
{
    int x = pos->x + tmp_x * 2;
    int y = pos->y + tmp_y * 2;

    if (data->map[y][x] == ' ' || data->map[y][x] == 'O') {
        data->map[y][x] = 'X';
        if (data->save[y - tmp_y][x - tmp_x] == 'X')
            data->map[y - tmp_y][x - tmp_x] = ' ';
        else if (data->save[y - tmp_y][x - tmp_x] == 'P')
            data->map[y - tmp_y][x - tmp_x] = ' ';
        else
            data->map[y - tmp_y][x - tmp_x] = data->save[y - tmp_y][x - tmp_x];
        if (data->save[y][x] == 'O')
            data->reaming -= 1;
        if (data->save[y - tmp_y][x - tmp_x] == 'O')
            data->reaming += 1;
    }
}

void move_player(int tmp_x, int tmp_y, map_t *data)
{
    point_t *pos = data->pos;
    char **map = data->map;
    int x = pos->x + tmp_x;
    int y = pos->y + tmp_y;

    if (x >= 0 && x < data->w && y >= 0 && y < data->h) {
        if (map[y][x] == 'X') {
            move_box(data, tmp_x, tmp_y, pos);
        }
        if (map[y][x] == ' ' || map[y][x] == 'O') {
            compare_map(data, pos);
            map[y][x] = 'P';
            pos->x = x;
            pos->y = y;
        }
    }
}