/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** game_loop
*/

#include "runner.h"
#include "game_loop.h"
#include "create_const.h"
#include "menu_h.h"

void loop_game(sfRenderWindow *window, game_data_t *game_data)
{
    verif_pos_perso(game_data);
    detect_wall(game_data);
    perso_jump(game_data);
    anim_sprite(game_data);
    display_sprite(game_data, window);
}

int runner_loop(sfRenderWindow *window, map_data_t *data_map, int loop)
{
    sfEvent event;
    sfBool quit = sfFalse;
    game_data_t *game_data = create_all_sprite(data_map);
    sprite_list_t *list_map = create_map_list(data_map);
    int exit_code = 2;

    if (game_data == NULL || list_map == NULL)
        return (84);
    game_data->list = list_map;
    game_data->loop = loop;
    while (quit != sfTrue && game_data->quit != sfTrue) {
        loop_game(window, game_data);
        game_event(&quit, event, window, game_data);
        sfRenderWindow_display(window);
        if (!sfRenderWindow_isOpen(window))
            return (84);
    }
    if (quit != sfTrue)
        exit_code = display_end_menu(window, game_data);
    free_game_data(game_data);
    return (exit_code);
}