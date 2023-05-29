/*
** EPITECH PROJECT, 2018
** duck sprite gestion part 2
** File description:
** duck sprite gestion part 2
*/

#include <math.h>
#include "my_hunter.h"

void to_dead_sprite(sprite_anim_t *my_duck)
{
    char *image = "resource/duck_dead_bleu.png";
    sfSprite *sprite = my_duck->sprite;
    sfVector2f scale = sfSprite_getScale(sprite);

    my_duck->texture = sfTexture_createFromFile(image, NULL);
    sfSprite_setTexture(sprite, my_duck->texture, sfTrue);
    my_duck->speed = create_vector(0, 6);
}

sfVector2f create_speed(float x, float y, sfVector2f dep)
{
    sfVector2f temp;
    float temp_x = (x - dep.x) / 200;
    float temp_y = fabs(y - dep.y) / -300;

    temp = create_vector(temp_x, temp_y);
    return (temp);
}

sprite_anim_t **regenerate_sprite(sprite_anim_t **sprite)
{
    sfVector2f dep;
    sprite_anim_t *temp;
    sfVector2f scale;

    for (int i = 0 ; i < DUCK_NB ; i += 1) {
        temp = sprite[i];
        dep = create_vector(alea(150, 700), 650);
        temp->dest_x = alea(0, WINDOW_WIDTH);
        temp->dest_y = -50;
        scale = create_scale((temp->dest_x - dep.x), DUCK_S);
        temp->rect = create_rect(alea(0, 3) * 37, 0, 37, 32);
        temp->speed = create_speed(temp->dest_x, temp->dest_y, dep);
        temp->dead = 0;
        temp->texture = sfTexture_createFromFile(IMG_DUCK, NULL);
        temp->sprite = sfSprite_create();
        sfSprite_setTexture(temp->sprite, temp->texture, sfTrue);
        sfSprite_setTextureRect(temp->sprite, temp->rect);
        sfSprite_setPosition(temp->sprite, dep);
        sfSprite_setScale(temp->sprite, scale);
    }
    return (sprite);
}

sprite_anim_t *change_dir(sprite_anim_t *my_sprite)
{
    sfVector2f speed = my_sprite->speed;
    sfVector2f pos = sfSprite_getPosition(my_sprite->sprite);
    sfSprite *sprite = my_sprite->sprite;

    if (pos.x - DUCK_W * DUCK_S < 0 && speed.x < 0) {
        my_sprite->speed = create_vector(-speed.x, speed.y);
        sfSprite_setScale(sprite, create_scale(DUCK_S, DUCK_S));
        sfSprite_setPosition(sprite, create_vector(pos.x - DUCK_TW, pos.y));
    }
    if (pos.y < 0) {
        my_sprite->speed = create_vector(speed.x, -speed.y);
    }
    if (pos.x + DUCK_W * DUCK_S > WINDOW_WIDTH && speed.x > 0) {
        my_sprite->speed = create_vector(-speed.x, speed.y);
        sfSprite_setScale(sprite, create_scale(-DUCK_S, DUCK_S));
        sfSprite_setPosition(sprite, create_vector(pos.x + DUCK_TW, pos.y));
    }
    if (pos.y > 500 && my_sprite->dead == 0 && speed.y > 0) {
        my_sprite->speed = create_vector(speed.x, -speed.y);
    }
    return (my_sprite);
}

void regenerate_all(my_sprite_t *sprite)
{
    if (sprite->duck_reaming == 0) {
        regenerate_sprite(sprite->my_duck);
        sprite->duck_reaming = DUCK_NB;
        sprite->duck_alive = DUCK_NB;
        sprite->shot = 3;
    }
}