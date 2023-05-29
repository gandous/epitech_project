/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** end_menu
*/

#include <stdlib.h>
#include "runner.h"
#include "menu_h.h"
#include "game_loop.h"
#include "create_const.h"
#include "data_name.h"

end_menu_t *create_end_menu(char *score)
{
    end_menu_t *menu_data = NULL;
    sfVector2f pos = create_vec(WINDOW_W / 2 - BUTTON_W / 2, 200);
    sfColor col = create_color(0, 0, 0, 255);

    menu_data = malloc(sizeof(end_menu_t));
    if (menu_data == NULL)
        return (NULL);
    menu_data->text_titre = create_text(pos, FONT, "score :", col);
    sfText_setCharacterSize(menu_data->text_titre->text, TEXT_SIZE);
    pos.y += 100;
    menu_data->text_score = create_text(pos, FONT, score, col);
    sfText_setCharacterSize(menu_data->text_score->text, TEXT_SIZE - 20);
    pos.y += 200;
    menu_data->replay_b = create_static_s(IMG_REPLAY_B, pos, 1);
    pos.y += 200;
    menu_data->quit_b = create_static_s(IMG_QUIT_B, pos, 1);
    if (menu_data->replay_b == NULL || menu_data->quit_b == NULL)
        return (NULL);
    return (menu_data);
}

void free_end_menu(end_menu_t *menu_data)
{
    free_static_s(menu_data->replay_b);
    free_static_s(menu_data->quit_b);
    free_text(menu_data->text_titre);
    free_text(menu_data->text_score);
    free(menu_data);
}

void display_end(sfRenderWindow *win, end_menu_t *menu_data)
{
    sfRenderWindow_drawText(win, menu_data->text_titre->text, NULL);
    sfRenderWindow_drawText(win, menu_data->text_score->text, NULL);
    sfRenderWindow_drawSprite(win, menu_data->replay_b->sprite, NULL);
    sfRenderWindow_drawSprite(win, menu_data->quit_b->sprite, NULL);
    sfRenderWindow_display(win);
}

int display_end_menu(sfRenderWindow *win, game_data_t *game_data)
{
    end_menu_t *menu_data = create_end_menu(game_data->score_str);
    int status = 3;
    sfEvent event;

    if (menu_data == NULL)
        return (0);
    while (status > 2) {
        status = end_menu_event(win, event, menu_data);
        display_end(win, menu_data);
    }
    end_animation(game_data, win);
    free_end_menu(menu_data);
    return (status);
}