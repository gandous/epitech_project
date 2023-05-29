/*
** EPITECH PROJECT, 2018
** create sprite
** File description:
** create a sprite with the image given as argumentss
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_hunter.h"

sfSprite *create_sprite(char *image, int scale)
{
    sfSprite *sprite;
    sfTexture *texture;

    texture = sfTexture_createFromFile(image, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, create_vector(scale, scale));
    return (sprite);
}

sprite_stat_t *create_stat_sprite(char *filepath, float scale)
{
    sprite_stat_t *temp = NULL;

    temp = malloc(sizeof(sprite_stat_t));
    if (temp == NULL)
        return (NULL);
    temp->texture = sfTexture_createFromFile(filepath, NULL);
    temp->sprite = sfSprite_create();
    sfSprite_setTexture(temp->sprite, temp->texture, sfTrue);
    sfSprite_setScale(temp->sprite, create_vector(scale, scale));
    return (temp);
}

void delete_stat_sprite(sprite_stat_t *sprite)
{
    sfTexture_destroy(sprite->texture);
    sfSprite_destroy(sprite->sprite);
}

void create_all_2(my_sprite_t *temp)
{
    temp->foreground = create_stat_sprite("resource/background_1.png", 4);
    temp->background = create_stat_sprite("resource/background.png", 4);
    temp->crosshair = create_stat_sprite(IMG_CROSSHAIR, CROSS_S);
}

my_sprite_t *create_all_sprite(void)
{
    my_sprite_t *temp = malloc(sizeof(my_sprite_t));

    if (temp ==  NULL)
        return (NULL);
    temp->my_duck = create_duck_sprite(DUCK_NB);
    temp->duck_reaming = DUCK_NB;
    temp->duck_alive = DUCK_NB;
    temp->ball = create_ball();
    temp->shot = 3;
    temp->text = create_text();
    temp->score = 0;
    temp->score_c = create_score();
    temp->s_duck = load_sound(S_DUCK);
    temp->s_gunshot = load_sound(S_GUN);
    temp->s_shell = load_sound(S_SHELL);
    temp->s_music = sfMusic_createFromFile(S_MUSIC);
    play_music(temp->s_music);
    temp->clock = sfClock_create();
    create_all_2(temp);
    return (temp);
}