/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** calc_jump
*/

#include <math.h>
#include "runner.h"
#include "create_const.h"
#include "data_name.h"
#include "game_loop.h"

void calc_jump(game_data_t *game_data, double spd, double angle, float speed)
{
    sprite_anim_t *perso = NULL;

    perso = game_data->perso;
    if (game_data->perso_jump == 1) {
        change_texture(perso, IMG_PERSOH_JUMP, PERSO_W, PERSO_JUMP_H);
        game_data->perso_jump = 2;
        sfClock_restart(game_data->jump_clock);
    }
    if (game_data->perso_jump > 0) {
        spd = -8 * time_tosecond(game_data->jump_clock) +  speed * sin(angle);
        game_data->perso_y = spd  * -1;
        sfSprite_move(perso->sprite, create_vec(0, game_data->perso_y));
    }
    if (player_touch_ground(game_data) == 1 && game_data->perso_y > 0)
        game_data->perso_jump = 0;
}
