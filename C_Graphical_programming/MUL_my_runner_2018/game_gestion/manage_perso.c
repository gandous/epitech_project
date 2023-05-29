/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** manage_perso
*/

#include <stdio.h>
#include <math.h>
#include "runner.h"
#include "create_const.h"
#include "data_name.h"
#include "game_loop.h"

sprite_anim_t *create_perso(map_data_t *map_data)
{
    sprite_anim_t *perso = NULL;
    float pos_y = 0;

    for (int i = 0 ; i < map_data->height ; i += 1)
        if (map_data->map[i][3] == 'p' || map_data->map[i][3] == 'P')
            pos_y = i * TILE_SIZE - PERSO_H / 2;
    perso = create_anim_s(IMG_PERSOH, create_vec(230, pos_y), 1);
    if (perso == NULL)
        return (NULL);
    perso->frame = create_rect(0, 0, PERSO_W, PERSO_H);
    sfSprite_setTextureRect(perso->sprite, perso->frame);
    return (perso);
}

void change_texture(sprite_anim_t *perso, const char* img, float w, float h)
{
    sfTexture_destroy(perso->texture);
    perso->texture = sfTexture_createFromFile(img, NULL);
    sfSprite_setTexture(perso->sprite, perso->texture, sfTrue);
    perso->frame = create_rect(0, 0, w, h);
    sfSprite_setTextureRect(perso->sprite, perso->frame);
}

void anim_perso(sprite_anim_t *perso, int perso_jump)
{
    move_rect(&(perso->frame), PERSO_W, PERSO_TOT_W);
    if (perso_jump > 0 && perso_jump != 3 && (perso->frame).left == 0) {
        change_texture(perso, IMG_PERSOH, PERSO_W, PERSO_H);
    }
    sfSprite_setTextureRect(perso->sprite, perso->frame);
}

void verif_pos_perso(game_data_t *game_data)
{
    sfVector2f pos = sfSprite_getPosition(game_data->perso->sprite);

    if (pos.y > WINDOW_H)
        game_data->quit = sfTrue;
}

void perso_jump(game_data_t *game_data)
{
    float speed = 10;
    double angle = M_PI/6;
    double spd = 0;

    if (game_data->perso_jump == 0) {
        if (player_touch_ground(game_data) == 1)
            return;
        else {
            game_data->perso_jump = 3;
            sfClock_restart(game_data->jump_clock);
        }
    }
    if (game_data->perso_jump == 3)
        speed *= -0.5;
    calc_jump(game_data, spd, angle, speed);
}