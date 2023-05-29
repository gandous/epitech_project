/*
** EPITECH PROJECT, 2018
** time convertion
** File description:
** time gestion
*/

#include <SFML/System/Clock.h>

float time_tosecond(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    return (time.microseconds / 1000000.0);
}