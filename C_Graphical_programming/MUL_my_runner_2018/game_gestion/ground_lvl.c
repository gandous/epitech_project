/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** ground_lvl
*/

#include <stdio.h>
#include <math.h>
#include "game_loop.h"
#include "runner.h"
#include "data_name.h"
#include "create_const.h"

int player_touch_ground(game_data_t *game_data)
{
    char **map = game_data->map->map;
    int index = game_data->index_perso;
    sfVector2f pos = sfSprite_getPosition(game_data->perso->sprite);
    int index_y = (pos.y + (game_data->perso->frame).height) / TILE_SIZE;

    if (index_y >= game_data->map->height)
        return (0);
    if (map[index_y][index] == '1' || map[index_y][index + 1] == '1') {
        return (1);
    } else {
        return (0);
    }
}
