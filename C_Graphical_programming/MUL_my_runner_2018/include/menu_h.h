/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** end_menu
*/

#ifndef MENU_H_
#define MENU_H_

#include "runner.h"
#include "game_loop.h"

static char const IMG_REPLAY_B[] = "resource/replay_button.png";
static char const IMG_QUIT_B[] = "resource/quit_button.png";
static char const IMG_PLAY_B[] = "resource/play_button.png";
static int const BUTTON_W = 321;
static int const BUTTON_H = 98;
static int const TEXT_SIZE = 80;
static char const IMG_PRESENTATION[] = "resource/presentation.png";
static int const PRESENTATION_W = 500;
static int const PRESENTATION_H = 214;

typedef struct end_menu_s {
    sprite_static_t *replay_b;
    sprite_static_t *quit_b;
    text_data_t *text_titre;
    text_data_t *text_score;
} end_menu_t;

typedef struct start_menu_s {
    sprite_static_t *button_p;
    sprite_static_t *button_q;
    sprite_static_t *presentation;
} start_menu_t;

int display_start_menu(sfRenderWindow *win);
int start_menu_event(sfRenderWindow *win, sfEvent event, start_menu_t *menu_d);
int display_end_menu(sfRenderWindow *win, game_data_t *game_data);
int end_menu_event(sfRenderWindow *win, sfEvent event, end_menu_t *menu_data);
int menu_key_pressed(sfKeyEvent key);
int end_animation(game_data_t *game_data, sfRenderWindow *win);

#endif