/*
** EPITECH PROJECT, 2018
** sound gestion
** File description:
** for sound gestion
*/

#include "my_hunter.h"

sound_t *load_sound(char *filepath)
{
    sound_t *temp = NULL;

    temp = malloc(sizeof(sound_t));
    if (temp == NULL)
        return (NULL);
    temp->buff = sfSoundBuffer_createFromFile(filepath);
    temp->sound = sfSound_create();
    sfSound_setBuffer(temp->sound, temp->buff);
    return (temp);
}

void delete_sound(sound_t *sound)
{
    sfSound_destroy(sound->sound);
    sfSoundBuffer_destroy(sound->buff);
    free(sound);
}

void play_duck(my_sprite_t *sprite)
{
    if (alea(0, 3000) <= 10) {
        sfSound_play(sprite->s_duck->sound);
    }
}

void play_music(sfMusic *music)
{
    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
}
