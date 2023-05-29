/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** free_sprite
*/

#include <stdlib.h>
#include "runner.h"
#include "create_const.h"
#include "game_loop.h"

void free_game_data(game_data_t *game_data)
{
    free_bg(game_data->background);
    free_anim_s(game_data->perso);
    sfClock_destroy(game_data->clock);
    sfClock_destroy(game_data->jump_clock);
    free_list(game_data->list);
    sfMusic_destroy(game_data->jump_sound);
    sfMusic_destroy(game_data->death_sound);
    free(game_data);
}