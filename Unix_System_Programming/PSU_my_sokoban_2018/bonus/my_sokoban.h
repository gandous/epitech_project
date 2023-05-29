/*
** EPITECH PROJECT, 2018
** my sokoban
** File description:
** prototype
*/

#include <ncurses.h>

#ifndef MY_SOKOBAN_H_
#define MY_SOKOBAN_H_

#define SUCCES 0
#define ERROR 84

typedef struct point {
    int x;
    int y;
} point_t;

typedef struct map {
    char **map;
    char **save;
    int w;
    int h;
    point_t *pos;
    int reaming;
} map_t;

typedef struct win_size {
    int w;
    int h;
} win_size_t;

void free_2d_string(char **array);
int my_sokoban(char *filepath);
int check_event(int event, map_t *map_data, int *w_size, WINDOW *box);
void move_player(int tmp_x, int tmp_y, map_t *data);
void display_map(char **map, WINDOW *box);
void search_player(point_t *pos, char **map);
void copy_map(map_t *data);
void map_data_free(map_t *data);
void display_usage(void);
void display_center(char *str);
WINDOW *create_game_win(WINDOW *win, int w, int h);
int game_loop(char *filepath, bool color);
WINDOW *create_win_no_border(WINDOW *win, int w, int h);
WINDOW *create_win_no_border_no_y_center(WINDOW *win, int w, int h, int y);
void display_start_screen(bool color);
int create_menu(char **content, win_size_t size);
int my_strlen(char *str);
win_size_t create_win_size(int w, int h);
void game_menu(void);
int box_bloc(char **map, char **save);
void play_menu(bool color);
char **load_map_name(void);
int gestion_menu_princ(bool color);
int create_popup(char **txt, win_size_t size);
int display_end_game(bool color);

#endif
