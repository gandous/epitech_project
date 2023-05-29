/*
** EPITECH PROJECT, 2018
** manage mouse
** File description:
** manage all event for mouse
*/

#include <math.h>
#include "my_hunter.h"

int duck_is_touch(sfMouseButtonEvent mouse, sprite_anim_t *my_duck)
{
    sfVector2f duck;
    sfVector2f scale;
    float mouse_x = mouse.x * 1.0;
    float mouse_y = mouse.y * 1.0;
    float x_diff;
    float y_diff;

    if (my_duck->sprite == NULL)
        return (0);
    my_duck->speed = change_speed(my_duck->speed);
    duck = sfSprite_getPosition(my_duck->sprite);
    scale = sfSprite_getScale(my_duck->sprite);
    y_diff = fabs(mouse_y - (duck.y + (DUCK_W * DUCK_S) / 2));
    if (scale.x < 0)
        x_diff = fabs(mouse_x - (duck.x + (DUCK_TW) / 2) + (DUCK_TW));
    else
        x_diff = fabs(mouse_x - (duck.x + (DUCK_W * DUCK_S) / 2));
    if (x_diff < 60.0 && y_diff < 60.0) {
        return (1);
    } else
        return (0);
}

void manage_mouse_click(sfMouseButtonEvent mouse, my_sprite_t *all_sprite)
{
    sprite_anim_t **my_duck = all_sprite->my_duck;

    sfSound_play(all_sprite->s_gunshot->sound);
    for (int i = 0 ; i < DUCK_NB ; i += 1) {
        if (duck_is_touch(mouse, my_duck[i]) == 1 && my_duck[i]->dead != 1) {
            my_duck[i]->dead = 1;
            to_dead_sprite(my_duck[i]);
            all_sprite->duck_alive -= 1;
            all_sprite->score += 10;
            int_to_string(all_sprite->score, all_sprite->score_c);
            sfText_setString(all_sprite->text->text, all_sprite->score_c);
        }
    }
    all_sprite->shot -= 1;
    sfSound_play(all_sprite->s_shell->sound);
}

void analyse_event(sfRenderWindow *window, sfEvent event, my_sprite_t *sprite)
{
    while (sfRenderWindow_pollEvent(window, &event) == sfTrue) {
        switch (event.type) {
        case sfEvtMouseButtonPressed:
            manage_mouse_click(event.mouseButton, sprite);
            break;
        case sfEvtClosed:
            sfRenderWindow_close(window);
            break;
        case sfEvtKeyPressed:
            if (event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
            break;
        }
    }
}