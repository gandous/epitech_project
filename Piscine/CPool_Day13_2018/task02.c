/*
** EPITECH PROJECT, 2018
** open a window
** File description:
** open a window
*/

#include <SFML/Graphics/RenderWindow.h>

int main()
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfUint8 *pixel;

    video_mode.width = 800;
    video_mode.height = 600;
    video_mode.bitsPerPixel = 8;
    pixel = malloc(sizeof(sfUint8) * 600 * 800);
    pixel[0] = 255;
    pixel[1] = 125;
    pixel[2] = 0;
    pixel[3] = 255;
    window = sfRenderWindow_create(video_mode, "My Window", sfDefaultStyle, NULL);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return (0);
}
