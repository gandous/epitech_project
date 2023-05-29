/*
** EPITECH PROJECT, 2018
** sprite duck gestion
** File description:
** all function for duck sprite
*/

#include <stdlib.h>
#include <math.h>
#include "my_hunter.h"

sprite_anim_t *create_my_duck_sprite(char *image, int scale)
{
    sfSprite *sprite;
    sfTexture *texture;
    sprite_anim_t *temp = NULL;
    sfVector2f dep;

    texture = sfTexture_createFromFile(image, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    temp = malloc(sizeof(sprite_anim_t));
    temp->dest_x = alea(0, WINDOW_WIDTH);
    dep = create_vector(alea(150, 700), 650);
    sfSprite_setScale(sprite, create_scale((temp->dest_x - dep.x), DUCK_S));
    temp->sprite = sprite;
    sfSprite_setPosition(temp->sprite, dep);
    temp->dest_y = -50;
    temp->rect = create_rect(alea(0, 3) * 37, 0, 37, 32);
    temp->speed = create_speed(temp->dest_x, temp->dest_y, dep);
    temp->texture = texture;
    temp->dead = 0;
    sfSprite_setTextureRect(temp->sprite, temp->rect);
    return (temp);
}

sprite_anim_t **create_duck_sprite(int nombre)
{
    sprite_anim_t **temp = NULL;

    temp = malloc(sizeof(sprite_anim_t) * (nombre + 1));
    temp[nombre] = NULL;
    if (temp == NULL)
        return (NULL);
    for (int i = 0 ; i < nombre ; i += 1) {
        temp[i] = create_my_duck_sprite(IMG_DUCK, 3);
    }
    return (temp);
}

void display_duck(my_sprite_t *all_sprite, sfRenderWindow *window)
{
    sprite_anim_t **my_duck = all_sprite->my_duck;
    sfVector2f duck_pos;
    sfVector2f speed;
    int dead;

    if (all_sprite->duck_reaming == 0)
        return;
    for (int i = 0 ; DUCK_NB > i ; i += 1) {
        if (my_duck[i]->sprite != NULL) {
            speed = my_duck[i]->speed;
            dead = my_duck[i]->dead;
            sfSprite_move(my_duck[i]->sprite, my_duck[i]->speed);
            sfRenderWindow_drawSprite(window, my_duck[i]->sprite, NULL);
            my_duck[i] = change_dir(my_duck[i]);
            my_duck[i]->sprite = inside_the_screen(my_duck[i]->sprite);
            all_sprite->duck_reaming -= duck_is_nul(my_duck[i]->sprite);
        }
    }
}

void anim_duck(my_sprite_t *all_sprite)
{
    sprite_anim_t **my_duck = all_sprite->my_duck;

    if (all_sprite->duck_reaming == 0)
        return;
    for (int i = 0 ; DUCK_NB >  i ; i += 1) {
        if (my_duck[i]->sprite != NULL && my_duck[i]->dead == 0) {
            sfSprite_setTextureRect(my_duck[i]->sprite, my_duck[i]->rect);
            move_rect(&(my_duck[i]->rect), 37, 111);
        }
    }
}

void delete_duck(my_sprite_t *all_sprite)
{
    sprite_anim_t **my_duck = all_sprite->my_duck;

    for (int i = 0 ; DUCK_NB > i ; i += 1) {
        if (my_duck[i]->sprite != NULL) {
            sfSprite_destroy(my_duck[i]->sprite);
        }
        sfTexture_destroy(my_duck[i]->texture);
        free(my_duck[i]);
    }
    free(my_duck);
}