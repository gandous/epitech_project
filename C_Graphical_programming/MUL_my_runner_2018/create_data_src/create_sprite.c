/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** create_sprite
*/

#include <stdlib.h>
#include "runner.h"
#include "create_const.h"

sprite_anim_t *create_anim_s(const char *filepath, sfVector2f pos, float scale)
{
    sprite_anim_t *my_sprite = NULL;

    my_sprite = malloc(sizeof(sprite_anim_t));
    if (my_sprite == NULL)
        return (NULL);
    my_sprite->texture = sfTexture_createFromFile(filepath, NULL);
    my_sprite->sprite = sfSprite_create();
    sfSprite_setTexture(my_sprite->sprite, my_sprite->texture, sfTrue);
    sfSprite_setScale(my_sprite->sprite, create_vec(scale, scale));
    sfSprite_setPosition(my_sprite->sprite, pos);
    return (my_sprite);
}

void free_anim_s(sprite_anim_t *sprite)
{
    sfSprite_destroy(sprite->sprite);
    sfTexture_destroy(sprite->texture);
    free(sprite);
}

sprite_static_t *create_static_s(const char *file, sfVector2f pos, float s)
{
    sprite_static_t *my_sprite = NULL;

    my_sprite = malloc(sizeof(sprite_static_t));
    if (my_sprite == NULL)
        return (NULL);
    my_sprite->texture = sfTexture_createFromFile(file, NULL);
    my_sprite->sprite = sfSprite_create();
    sfSprite_setTexture(my_sprite->sprite, my_sprite->texture, sfTrue);
    sfSprite_setScale(my_sprite->sprite, create_vec(s, s));
    sfSprite_setPosition(my_sprite->sprite, pos);
    return (my_sprite);
}

void free_static_s(sprite_static_t *sprite)
{
    sfSprite_destroy(sprite->sprite);
    sfTexture_destroy(sprite->texture);
    free(sprite);
}