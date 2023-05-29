/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** window_manager
*/

#include "runner.h"

sfRenderWindow *create_window(char *name, int width, int height)
{
    sfRenderWindow *window;
    sfVideoMode mode = {width, height, 16};

    window = sfRenderWindow_create(mode, name, sfClose | sfFullscreen, NULL);
    if (window == NULL)
        return (NULL);
    sfRenderWindow_setFramerateLimit(window, 120);
    return (window);
}

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
    sfRenderWindow_destroy(window);
}