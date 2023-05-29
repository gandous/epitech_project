/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** runner
*/

#include "runner.h"
#include "game_loop.h"
#include "menu_h.h"
#include "data_name.h"

int runner_main_loop(sfRenderWindow *win, map_data_t *data_map, int loop)
{
    int game_status = 0;
    sfMusic *music = sfMusic_createFromFile(SOUND_MUSIC);

    if (music == NULL)
        return (84);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    sfMusic_setVolume(music, 50);
    while (game_status != 2) {
        game_status = display_start_menu(win);
        while (game_status == 0)
            game_status = runner_loop(win, data_map, loop);
    }
    sfMusic_destroy(music);
    return (0);
}

void print_helper(void)
{
    my_putstr("My runner\n\n");
    my_putstr("USAGE :\n");
    my_putstr("./my_runner [flag] map\n\n");
    my_putstr("DESCRIPTION :\n");
    my_putstr("flag   optional flag -i (play the map in infinity mode)\n");
    my_putstr("map    filepath to a file with a map (1 : block, 2 : spike)\n");
}

int lets_game(map_data_t *data_map, int loop)
{
    sfRenderWindow *win = create_window("my runner", WINDOW_W, WINDOW_H);
    runner_main_loop(win, data_map, loop);
    free_map_data(data_map);
    close_window(win);
    return (0);
}

int runner(int argc, char **argv)
{
    int loop = 0;
    map_data_t *data_map = NULL;;

    if (argc < 2 || argc > 3)
        return (84);
    if (argc == 3) {
        if (argv[1][0] == '-' && argv[1][1] == 'i')
            loop = 1;
        data_map = load_map(argv[2]);
    }else if (argc == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'h') {
            print_helper();
            return (0);
        }
        data_map = load_map(argv[1]);
    }
    if (data_map == NULL)
        return (84);
    lets_game(data_map, loop);
}