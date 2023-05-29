/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** detecte_wall
*/

#include "data_name.h"
#include "game_loop.h"

int detect_wall(game_data_t *game_data)
{
    char **map = game_data->map->map;
    sfVector2f pos = sfSprite_getPosition(game_data->perso->sprite);
    int index_y = (pos.y + (game_data->perso->frame).height / 1.1) / TILE_SIZE;

    if (index_y >= game_data->map->height)
        return (0);
    if (map[index_y][game_data->index_perso + 1] == '1') {
        if (game_data->perso_jump == 0) {
            game_data->quit = sfTrue;
            return (1);
        }
    }
    return (0);
}