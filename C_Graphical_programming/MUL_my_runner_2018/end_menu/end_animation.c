/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** end_animation
*/

#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "runner.h"
#include "game_loop.h"
#include "create_const.h"
#include "menu_h.h"

int alea(int min, int max)
{
    return (rand()%(max - min) + min);
}

void set_upanim(sprite_list_t *list)
{
    while (list != NULL) {
        list->is_spike = alea(1, 2);
        list->vect = create_vec(alea(0, 2), alea(2, 5));
        list = list->next;
    }
}

void make_anim(sprite_list_t *list, sfClock *clock, sfRenderWindow *win)
{
    float speed = 10;
    double angle = M_PI/6;
    double spd;

    while (list != NULL) {
        spd = -8 * time_tosecond(clock) +  speed * sin(angle);
        spd = spd  * -1 * list->vect.y;
        sfSprite_move(list->sprite, create_vec(list->vect.x, spd));
        sfSprite_rotate(list->sprite, list->is_spike);
        sfRenderWindow_drawSprite(win, list->sprite, NULL);
        list = list->next;
    }
}

int end_animation(game_data_t *game_data, sfRenderWindow *win)
{
    sfClock *time_anim = sfClock_create();

    srand(time(NULL));
    if (time_anim == NULL)
        return (84);
    set_upanim(game_data->list);
    while (time_tosecond(time_anim) < 1.5) {
        display_bg(game_data->background, win);
        make_anim(game_data->list, time_anim, win);
        sfRenderWindow_display(win);
        sfRenderWindow_clear(win, sfBlack);
    }
    sfClock_destroy(time_anim);
    return (0);
}