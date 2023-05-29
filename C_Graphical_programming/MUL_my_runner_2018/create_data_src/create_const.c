/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** create_vector
*/

#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>

sfVector2f create_vec(float x, float y)
{
    sfVector2f vector;
    vector.x = x;
    vector.y = y;
    return (vector);
}

sfIntRect create_rect(int x, int y, int width, int height)
{
    sfIntRect rect;
    rect.top = y;
    rect.left = x;
    rect.width = width;
    rect.height = height;
    return (rect);
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left >= max_value)
        rect->left = 0;
}

float time_tosecond(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    return (time.microseconds / 1000000.0);
}

sfColor create_color(int r, int g, int b, int a)
{
    sfColor color;
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
    return (color);
}