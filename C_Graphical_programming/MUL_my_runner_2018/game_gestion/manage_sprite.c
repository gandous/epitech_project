/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** manage_sprite
*/

#include <stdlib.h>
#include "runner.h"
#include "game_loop.h"
#include "data_name.h"
#include "create_const.h"

int verif_sprite(game_data_t *sprite)
{
    if (sprite->background == NULL || sprite->perso == NULL)
        return (84);
    return (0);
}

int create_sprite_part2(game_data_t *game_data)
{
    sfVector2f vec = create_vec(WINDOW_W - 350, 20);

    game_data->score = 0;
    game_data->score_str = malloc(sizeof(char) * 7);
    if (game_data == NULL)
        return (84);
    game_data->score_str[6] = '\0';
    for (int i = 0 ; i < 6 ; i += 1)
        game_data->score_str[i] = '0';
    game_data->clock_score = sfClock_create();
    game_data->bg_text = create_static_s(BG_WOOD_A, vec, 1);
    game_data->text_score = create_score_txt(game_data->score_str);
    game_data->quit = sfFalse;
    game_data->jump_sound = sfMusic_createFromFile(SOUND_JUMP);
    game_data->death_sound = sfMusic_createFromFile(SOUND_DEATH);
    return (0);
}

game_data_t *create_all_sprite(map_data_t *map_data)
{
    game_data_t *all_sprite = NULL;

    all_sprite = malloc(sizeof(game_data_t));
    if (all_sprite == NULL)
        return (NULL);
    all_sprite->background = create_bg();
    all_sprite->perso = create_perso(map_data);
    all_sprite->clock = sfClock_create();
    all_sprite->game_speed = GAME_SPEED;
    all_sprite->map = map_data;
    all_sprite->perso_jump = 0;
    all_sprite->perso_y = 845;
    all_sprite->jump_clock = sfClock_create();
    all_sprite->index_perso = 3;
    create_sprite_part2(all_sprite);
    if (verif_sprite(all_sprite) == 84) {
        return (NULL);
    }
    return (all_sprite);
}