/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** runner
*/

#ifndef RUNNER_H_
#define RUNNER_H_

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

static const int WINDOW_H = 1080;
static const int WINDOW_W = 1920;

typedef struct sprite_anim_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f vect;
    sfIntRect frame;
} sprite_anim_t;

typedef struct map_data_s {
    int width;
    int height;
    int index;
    char **map;
} map_data_t;

typedef struct sprite_static_s {
    sfSprite *sprite;
    sfTexture *texture;
} sprite_static_t;

typedef struct text_data_s {
    sfFont *font;
    sfText *text;
} text_data_t;

sfRenderWindow *create_window(char *name, int width, int height);
void close_window(sfRenderWindow *window);
int runner(int argc, char **argv);
map_data_t *load_map(char *filepath);
void free_map_data(map_data_t *data_map);
void my_putstr(char *str);

#endif
