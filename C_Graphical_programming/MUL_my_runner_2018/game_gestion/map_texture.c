/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** map_texture
*/

#include "runner.h"
#include "data_name.h"

sfTexture *get_texture(char **map, int x, int y, int height)
{
    sfTexture *texture = NULL;

    if (y > 1 && map[y][x] == '1') {
        if (map[y - 1][x] == '1')
            texture = sfTexture_createFromFile(IMG_TILE_DIRT, NULL);
        else
            texture = sfTexture_createFromFile(IMG_TILE_CENTER, NULL);
        return (texture);
    } else if (map[y][x] == '2') {
        texture = sfTexture_createFromFile(IMG_TILE_SPIKE, NULL);
        return (texture);
    }
    if (map[y][x] != 'p' && map[y][x] != 'P')
        texture = sfTexture_createFromFile(IMG_TILE_CENTER, NULL);
    return (texture);
}
