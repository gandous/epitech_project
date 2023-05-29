/*
** EPITECH PROJECT, 2018
** dog gestion
** File description:
** dog gestion
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "my_hunter.h"

void render_sp(sfRenderWindow *win, my_sprite_t *s, sprite_anim_t *dog, int v)
{
    sfRenderWindow_clear(win, sfBlack);
    sfRenderWindow_drawSprite(win, s->background->sprite, NULL);
    if (v == 1)
        sfRenderWindow_drawSprite(win, dog->sprite, NULL);
    sfRenderWindow_drawSprite(win, s->foreground->sprite, NULL);
    if (v != 1)
        sfRenderWindow_drawSprite(win, dog->sprite, NULL);
}

void anim_dog(my_sprite_t *sprite, sprite_anim_t *dog, int anim_s)
{
    if (time_tosecond(sprite->clock) > 0.07) {
        move_rect(&dog->rect, DOG_W, 224);
        sfSprite_setTextureRect(dog->sprite, dog->rect);
        sfClock_restart(sprite->clock);
    }
}

int change_status2(sprite_anim_t *dog, int stat, sfVector2f pos, sfClock *cloc)
{
    if (pos.y < 450 && stat == 2) {
        dog->speed = create_vector(1, 2);
        dog->rect = create_rect(37, 0, 37, 47);
        sfSprite_setTexture(dog->sprite, dog->texture, sfTrue);
        sfSprite_setTextureRect(dog->sprite, dog->rect);
        sfClock_restart(cloc);
        return (1);
    }
    if (pos.y > 600 && stat == 1 && time_tosecond(cloc) > 1) {
        return (0);
    }
    return (stat);
}

int change_status(sprite_anim_t *dog, int stat, sfClock *clock)
{
    sfVector2f pos = sfSprite_getPosition(dog->sprite);

    if (pos.x > 420 && stat == 4) {
        dog->texture = sfTexture_createFromFile(IMG_DOG_FIND, NULL);
        dog->speed = create_vector(0, 0);
        sfSprite_setTexture(dog->sprite, dog->texture, sfTrue);
        sfClock_restart(clock);
        return (3);
    }
    if (time_tosecond(clock) > 1 && stat == 3) {
        dog->texture = sfTexture_createFromFile(IMG_DOG_JUMP, NULL);
        dog->speed = create_vector(1, -2);
        dog->rect = create_rect(0, 0, 37, 47);
        sfSprite_setTexture(dog->sprite, dog->texture, sfTrue);
        sfSprite_setTextureRect(dog->sprite, dog->rect);
        return (2);
    }
    return (change_status2(dog, stat, pos, clock));
}

void anim_intro(sfRenderWindow *window, my_sprite_t *sprite)
{
    int anim_fini = 4;
    sprite_anim_t *dog = create_anim(IMG_DOG_SEARCH, DOG_S);
    sfEvent event;

    while (sfRenderWindow_isOpen(window) && anim_fini != 0) {
        render_sp(window, sprite, dog, anim_fini);
        sfSprite_move(dog->sprite, dog->speed);
        if (anim_fini == 4)
            anim_dog(sprite, dog, anim_fini);
        anim_fini = change_status(dog, anim_fini, sprite->clock);
        analyse_event(window, event, sprite);
        sfRenderWindow_display(window);
    }
    delete_anim(dog);
}