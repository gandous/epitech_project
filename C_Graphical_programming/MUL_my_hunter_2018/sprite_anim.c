/*
** EPITECH PROJECT, 2018
** sprite anim
** File description:
** create an anim sprite
*/

#include "my_hunter.h"

sprite_anim_t *create_anim(char *filepath, float scale)
{
    sprite_anim_t *temp = NULL;

    temp = malloc(sizeof(sprite_anim_t));
    if (temp == NULL)
        return (NULL);
    temp->texture = sfTexture_createFromFile(filepath, NULL);
    temp->sprite = sfSprite_create();
    temp->rect = create_rect(0, 0, DOG_W, DOG_H);
    sfSprite_setTexture(temp->sprite, temp->texture, sfTrue);
    sfSprite_setScale(temp->sprite, create_vector(scale, scale));
    sfSprite_setTextureRect(temp->sprite, temp->rect);
    sfSprite_setPosition(temp->sprite, create_vector(-100, 615));
    temp->speed = create_vector(1, 0);
    return (temp);
}

void delete_anim(sprite_anim_t *temp)
{
    sfTexture_destroy(temp->texture);
    sfSprite_destroy(temp->sprite);
    free(temp);
}
