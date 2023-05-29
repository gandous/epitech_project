/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** display_game_data
*/

#include "runner.h"
#include "game_loop.h"
#include "create_const.h"
#include <stdlib.h>

void anim_sprite(game_data_t *game_data)
{
    if (time_tosecond(game_data->clock) > 0.07) {
        sfClock_restart(game_data->clock);
        anim_perso(game_data->perso, game_data->perso_jump);
    }
}

void display_sprite(game_data_t *game_data, sfRenderWindow *win)
{
    sfRenderWindow_clear(win, sfBlack);
    display_bg(game_data->background, win);
    display_map(&game_data->list, win, game_data);
    update_score(win, game_data);
    sfRenderWindow_drawSprite(win, game_data->perso->sprite, NULL);
}
