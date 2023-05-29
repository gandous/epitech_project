/*
** EPITECH PROJECT, 2018
** create const
** File description:
** create const
*/

#include <SFML/Graphics/Rect.h>
#include <SFML/System/Vector2.h>
#include "my_hunter.h"

sfIntRect create_rect(int x, int y, int width, int height)
{
    sfIntRect temp;
    temp.left = x;
    temp.top = y;
    temp.width = width;
    temp.height = height;
    return (temp);
}

sfVector2f create_vector(float x, float y)
{
    sfVector2f temp;
    temp.x = x;
    temp.y = y;
    return (temp);
}

sfVector2f create_scale(float direction, float scale)
{
    if (direction < 0) {
        return (create_vector(-scale, scale));
    } else {
        return (create_vector(scale, scale));
    }
}

sfSprite *inside_the_screen(sfSprite *my_sprite)
{
    sfVector2f pos = sfSprite_getPosition(my_sprite);

    if (pos.y > WINDOW_HEIGHT) {
        sfSprite_destroy(my_sprite);
        return (NULL);
    } else
        return (my_sprite);
}

int duck_is_nul(sfSprite *sprite)
{
    if (sprite == NULL)
        return (1);
    else
        return (0);
}