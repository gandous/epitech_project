/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** manage_map
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "data_name.h"
#include "game_loop.h"
#include "create_const.h"

sprite_list_t *create_elem(char **map, map_data_t *m_data, int i, sfVector2f p)
{
    sprite_list_t *temp = NULL;
    sfTexture *texture = NULL;

    if (map[i][m_data->index] == ' ' || map[i][m_data->index] == 'p')
        return (NULL);
    temp = malloc(sizeof(sprite_list_t));
    if (temp == NULL)
        return (NULL);
    texture = get_texture(map, m_data->index, i, m_data->height);
    temp->texture = texture;
    temp->sprite = sfSprite_create();
    sfSprite_setTexture(temp->sprite, temp->texture, sfTrue);
    sfSprite_setPosition(temp->sprite, p);
    temp->vect = create_vec(GAME_SPEED, 0);
    if (map[i][m_data->index] == '2')
        temp->is_spike = 1;
    else
        temp->is_spike = 0;
    return (temp);
}

sprite_list_t *create_line(map_data_t *map_data, sprite_list_t *list, int x)
{
    sprite_list_t *temp = NULL;
    char **map = map_data->map;
    int y = 0;
    sfTexture *texture;

    for (int i = 0 ; i < map_data->height ; i += 1) {
        temp = create_elem(map, map_data, i, create_vec(x, y));
        if (temp != NULL) {
            temp->next = list;
            list = temp;
        } else if (temp == NULL && map[i][map_data->index] != ' ' && map[i][map_data->index] != 'p')
            return (NULL);
        y += TILE_SIZE;
    }
    if (temp != NULL)
        return (temp);
    else
        return (list);
}

sprite_list_t *create_map_list(map_data_t *map)
{
    sprite_list_t *list = NULL;
    int x = 0;

    for (int i = 0 ; map->map[i] != NULL ; i += 1)
    map->index = 0;
    for (int i = 0 ; i <= WINDOW_W / TILE_SIZE && i < map->width; i += 1) {
        list = create_line(map, list, x);
        if (list == NULL)
            return (NULL);
        x += TILE_SIZE;
        map->index += 1;
    }
    return (list);
}

void spike_is_touch(sfVector2f pos_s, game_data_t *game_data)
{
    sfVector2f pos_perso = sfSprite_getPosition(game_data->perso->sprite);

    pos_perso.x += PERSO_W / 2;
    pos_perso.y += PERSO_H / 2;
    pos_s.x += TILE_SIZE / 2;
    pos_s.y += TILE_SIZE / 2;
    if (fabs(pos_perso.x - pos_s.x) < 60 && fabs(pos_perso.y - pos_s.y) < 60) {
        game_data->quit = sfTrue;
        sfMusic_play(game_data->death_sound);
    }
}

void display_map(sprite_list_t **my_list, sfRenderWindow *win, game_data_t *d)
{
    sprite_list_t *list = *my_list;
    sprite_list_t *previous = NULL;
    sfVector2f pos;

    while (list != NULL) {
        sfSprite_move(list->sprite, list->vect);
        sfRenderWindow_drawSprite(win, list->sprite, NULL);
        pos = sfSprite_getPosition(list->sprite);
        if (pos.x <= 0 - TILE_SIZE) {
            update_map(my_list, previous, d);
            break;
        }
        if (list->is_spike == 1 && pos.x < 500)
            spike_is_touch(pos, d);
        previous = list;
        list = list->next;
    }
}