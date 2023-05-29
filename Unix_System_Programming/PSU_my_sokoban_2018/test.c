/*
** EPITECH PROJECT, 2018
** my sokoban
** File description:
** test file for sokoban
*/

#include <criterion/criterion.h>
#include "my_sokoban.h"
#include "load_file.h"

Test (sokoban, check_map_load)
{
    map_t *data = load_file("map");
    char map_sur[8][10] = {"########", "# X   O#", "#  P   #",
    "###   X#", "##    O#", "#      #", "########", "\0"};

    cr_assert_str_eq(data->map[0], map_sur[0]);
    cr_assert_str_eq(data->map[1], map_sur[1]);
    cr_assert_str_eq(data->map[2], map_sur[2]);
    cr_assert_str_eq(data->map[3], map_sur[3]);
    cr_assert_str_eq(data->map[4], map_sur[4]);
    cr_assert_str_eq(data->map[5], map_sur[5]);
    cr_assert_str_eq(data->map[6], map_sur[6]);
    cr_assert_eq(data->h, 7);
    cr_assert_eq(data->w, 9);
    cr_assert_eq(data->reaming, 2);
    cr_assert_eq(data->pos->x, 3);
    cr_assert_eq(data->pos->y, 2);
    map_data_free(data);
}

Test (sokoban, check_map_copy)
{
    map_t *data = load_file("map");

    move_player(1, 0, data);
    cr_assert_str_eq(data->map[0], "########");
    cr_assert_str_eq(data->map[1], "# X   O#");
    cr_assert_str_eq(data->map[2], "#   P  #");
    cr_assert_str_eq(data->map[3], "###   X#");
    cr_assert_str_eq(data->map[4], "##    O#");
    cr_assert_str_eq(data->map[5], "#      #");
    cr_assert_str_eq(data->map[6], "########");
    map_data_free(data);
}

Test (sokoban, event_go_up)
{
    map_t *data = load_file("map");
    int w_size = 0;
    WINDOW *win = NULL;

    initscr();
    win = newwin(5, 5, 5, 5);
    check_event(65, data, &w_size, win);
    cr_assert_str_eq(data->map[0], "########");
    cr_assert_str_eq(data->map[1], "# XP  O#");
    cr_assert_str_eq(data->map[2], "#      #");
    cr_assert_str_eq(data->map[3], "###   X#");
    cr_assert_str_eq(data->map[4], "##    O#");
    cr_assert_str_eq(data->map[5], "#      #");
    cr_assert_str_eq(data->map[6], "########");
    map_data_free(data);
    delwin(win);
    endwin();
}

Test (sokoban, event_go_down)
{
    map_t *data = load_file("map");
    int w_size = 0;
    WINDOW *win = NULL;

    initscr();
    win = newwin(5, 5, 5, 5);
    check_event(66, data, &w_size, win);
    cr_assert_str_eq(data->map[0], "########");
    cr_assert_str_eq(data->map[1], "# X   O#");
    cr_assert_str_eq(data->map[2], "#      #");
    cr_assert_str_eq(data->map[3], "###P  X#");
    cr_assert_str_eq(data->map[4], "##    O#");
    cr_assert_str_eq(data->map[5], "#      #");
    cr_assert_str_eq(data->map[6], "########");
    map_data_free(data);
    delwin(win);
    endwin();
}

Test (sokoban, event_go_right)
{
    map_t *data = load_file("map");
    int w_size = 0;
    WINDOW *win = NULL;

    initscr();
    win = newwin(5, 5, 5, 5);
    check_event(67, data, &w_size, win);
    cr_assert_str_eq(data->map[0], "########");
    cr_assert_str_eq(data->map[1], "# X   O#");
    cr_assert_str_eq(data->map[2], "#   P  #");
    cr_assert_str_eq(data->map[3], "###   X#");
    cr_assert_str_eq(data->map[4], "##    O#");
    cr_assert_str_eq(data->map[5], "#      #");
    cr_assert_str_eq(data->map[6], "########");
    map_data_free(data);
    delwin(win);
    endwin();
}

Test (sokoban, event_go_left)
{
    map_t *data = load_file("map");
    int w_size = 0;
    WINDOW *win = NULL;

    initscr();
    win = newwin(5, 5, 5, 5);
    check_event(68, data, &w_size, win);
    cr_assert_str_eq(data->map[0], "########");
    cr_assert_str_eq(data->map[1], "# X   O#");
    cr_assert_str_eq(data->map[2], "# P    #");
    cr_assert_str_eq(data->map[3], "###   X#");
    cr_assert_str_eq(data->map[4], "##    O#");
    cr_assert_str_eq(data->map[5], "#      #");
    cr_assert_str_eq(data->map[6], "########");
    map_data_free(data);
    delwin(win);
    endwin();
}