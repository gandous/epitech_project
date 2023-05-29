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
#define MAX_WIDTH 50
#define MAX_HEIGHT 50

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

#endif
