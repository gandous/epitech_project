/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** generate_new_col
*/

#include <stdlib.h>
#include "runner.h"
#include "game_loop.h"
#include "data_name.h"

void free_list(sprite_list_t *list)
{
    sprite_list_t *temp = NULL;

    while (list != NULL) {
        temp = list->next;
        sfSprite_destroy(list->sprite);
        sfTexture_destroy(list->texture);
        free(list);
        list = temp;
    }
}

void update_map(sprite_list_t **list, sprite_list_t *previous, game_data_t *d)
{
    float pos = WINDOW_W;
    map_data_t *m = d->map;

    free_list(previous->next);
    previous->next = NULL;
    if (d->loop == 0 && d->index_perso >= m->width - 1) {
        d->quit = sfTrue;
        return;
    }
    if (m->index >= m->width && d->loop == 0) {
        d->index_perso += 1;
        return;
    } else if (d->loop == 1 && m->index >= m->width)
        m->index = 0;
    *list = create_line(m, *list, pos);
    m->index += 1;
    d->index_perso += 1;
    if (d->index_perso >= m->width)
        d->index_perso = 0;
}