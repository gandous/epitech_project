/*
** EPITECH PROJECT, 2018
** window maneger
** File description:
** window manager contains all function for window
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>

sfRenderWindow *create_window(char *name, int width, int height)
{
    sfRenderWindow *window;
    sfVideoMode mode = {width, height, 16};

    window = sfRenderWindow_create(mode, name, sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 120);
    return (window);
}

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
    sfRenderWindow_destroy(window);
}