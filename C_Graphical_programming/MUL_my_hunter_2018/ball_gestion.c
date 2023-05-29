/*
** EPITECH PROJECT, 2018
** ball gestion
** File description:
** contains all function to control shot
*/

#include "my_hunter.h"

sprite_stat_t **create_ball(void)
{
    sprite_stat_t **temp = NULL;
    sprite_stat_t *sprite = NULL;
    float pos_x = 103;

    temp = malloc(sizeof(sprite_anim_t) * 3);
    if (temp == NULL)
        return (NULL);
    for (int i = 0 ; i < 3 ; i += 1) {
        sprite = malloc(sizeof(sprite_anim_t));
        if (sprite == NULL)
            return (NULL);
        sprite->texture = sfTexture_createFromFile(IMG_BALL, NULL);
        sprite->sprite = sfSprite_create();
        sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
        sfSprite_setScale(sprite->sprite, create_vector(4, 4));
        sfSprite_setPosition(sprite->sprite, create_vector(pos_x, 832));
        pos_x += 33;
        temp[i] = sprite;
    }
    return (temp);
}

void display_ball(sfRenderWindow *win, sprite_stat_t **all, int shot)
{
    sprite_stat_t *sprite;

    for (int i = 0 ; i < shot ; i += 1) {
        sprite = all[i];
        if (sprite != NULL) {
            sfRenderWindow_drawSprite(win, sprite->sprite, NULL);
        }
    }
}

void delete_ball(sprite_stat_t **all_sprite)
{
    for (int i = 0 ; i < 3 ; i += 1) {
        if (all_sprite[i]->sprite != NULL)
            sfSprite_destroy(all_sprite[i]->sprite);
        sfTexture_destroy(all_sprite[i]->texture);
        free(all_sprite[i]);
    }
    free(all_sprite);
}