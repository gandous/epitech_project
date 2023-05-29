/*
** EPITECH PROJECT, 2018
** anim
** File description:
** move the rect to the good pos to animate
*/

#include <SFML/Graphics/Rect.h>

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left >= max_value)
        rect->left = 0;
}