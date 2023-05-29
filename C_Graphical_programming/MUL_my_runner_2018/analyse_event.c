/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** analyse_event
*/

#include <stdio.h>
#include "game_loop.h"
#include "data_name.h"
#include "create_const.h"
#include "runner.h"

void detect_key_pressed(sfKeyEvent key, sfBool *quit, game_data_t *data)
{
    switch (key.code) {
    case sfKeyEscape:
        *quit = sfTrue;
        break;
    case sfKeySpace:
        if (data->perso_jump == 0) {
            data->perso_jump = 1;
            sfMusic_play(data->jump_sound);
        }
        break;
    }
}

void game_event(sfBool *q, sfEvent event, sfRenderWindow *w, game_data_t *d)
{
    while (sfRenderWindow_pollEvent(w, &event)) {
        switch(event.type) {
        case sfEvtClosed:
            *q = sfTrue;
            break;
        case sfEvtKeyPressed:
            detect_key_pressed(event.key, q, d);
            break;
        }
    }
}