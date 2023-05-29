/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** start_menu
*/

#include <stdlib.h>
#include "runner.h"
#include "game_loop.h"
#include "create_const.h"
#include "menu_h.h"

start_menu_t *create_start_sprite(void)
{
    start_menu_t *menu_data = NULL;
    sfVector2f pos = create_vec(WINDOW_W / 2 - BUTTON_W / 2, 600);
    sfVector2f pos_pres = create_vec(WINDOW_W / 2 - PRESENTATION_W /2, 300);

    menu_data = malloc(sizeof(start_menu_t));
    if (menu_data == NULL)
        return (NULL);
    menu_data->presentation = create_static_s(IMG_PRESENTATION, pos_pres, 1);
    menu_data->button_p = create_static_s(IMG_PLAY_B, pos, 1);
    pos.y += 100;
    menu_data->button_q = create_static_s(IMG_QUIT_B, pos, 1);
    if (menu_data->presentation == NULL || menu_data->button_p == NULL)
        return (NULL);
    if (menu_data->button_p == NULL)
        return (NULL);
    return (menu_data);
}

void display_start_sprite(sfRenderWindow *win, start_menu_t *menu_data)
{
    sfRenderWindow_drawSprite(win, menu_data->presentation->sprite, NULL);
    sfRenderWindow_drawSprite(win, menu_data->button_p->sprite, NULL);
    sfRenderWindow_drawSprite(win, menu_data->button_q->sprite, NULL);
}

void free_start_menu(start_menu_t *menu_data)
{
    free_static_s(menu_data->button_p);
    free_static_s(menu_data->button_q);
    free_static_s(menu_data->presentation);
    free(menu_data);
}

int display_start_menu(sfRenderWindow *win)
{
    sprite_anim_t **bg_sprite = create_bg();
    start_menu_t *menu_data = create_start_sprite();
    int status = 3;
    sfEvent event;

    if (menu_data == NULL)
        return (2);
    while (status == 3) {
        status = start_menu_event(win, event, menu_data);
        display_bg(bg_sprite, win);
        display_start_sprite(win, menu_data);
        sfRenderWindow_display(win);
    }
    free_bg(bg_sprite);
    free_start_menu(menu_data);
    return (status);
}
