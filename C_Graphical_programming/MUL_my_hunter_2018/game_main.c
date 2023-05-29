/*
** EPITECH PROJECT, 2018
** game main
** File description:
** main function for the game
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "my_hunter.h"

int alea(int min, int max)
{
    return (rand()%(max - min) + min);
}

void display_sprite(sfRenderWindow *window, my_sprite_t *sprite)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_f = create_vector(mouse.x - CROSS_W, mouse.y - CROSS_H);

    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite->background->sprite, NULL);
    display_duck(sprite, window);
    sfRenderWindow_drawSprite(window, sprite->foreground->sprite, NULL);
    display_ball(window, sprite->ball, sprite->shot);
    display_text(window, sprite->text);
    sfSprite_setPosition(sprite->crosshair->sprite, mouse_f);
    sfRenderWindow_drawSprite(window, sprite->crosshair->sprite, NULL);
}

void remove_sprite(my_sprite_t *sprite)
{
    delete_duck(sprite);
    delete_ball(sprite->ball);
    delete_text(sprite->text);
    delete_sound(sprite->s_duck);
    delete_sound(sprite->s_gunshot);
    delete_sound(sprite->s_shell);
    delete_stat_sprite(sprite->background);
    delete_stat_sprite(sprite->foreground);
    delete_stat_sprite(sprite->crosshair);
    sfMusic_destroy(sprite->s_music);
    sfClock_destroy(sprite->clock);
    free(sprite->score_c);
}

void anim_sprite(my_sprite_t *sprite)
{
    if (time_tosecond(sprite->clock) > 0.07) {
        anim_duck(sprite);
        sfClock_restart(sprite->clock);
    }
}

void game(void)
{
    srand(time(NULL));
    sfRenderWindow *window;
    sfEvent event;
    my_sprite_t *sprite = create_all_sprite();

    window = create_window("Duck hunt", WINDOW_WIDTH, WINDOW_HEIGHT);
    anim_intro(window, sprite);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
        display_sprite(window, sprite);
        anim_sprite(sprite);
        regenerate_all(sprite);
        play_duck(sprite);
        sfRenderWindow_display(window);
        analyse_event(window, event, sprite);
        if (sprite->shot == 0 && sprite->duck_alive != 0)
            sfRenderWindow_close(window);
    }
    remove_sprite(sprite);
    sfRenderWindow_destroy(window);
}