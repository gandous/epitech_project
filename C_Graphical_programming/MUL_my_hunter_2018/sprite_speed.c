/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** sprite speed
*/

#include "my_hunter.h"

sfVector2f change_speed(sfVector2f speed)
{
    if (alea(1, 10) == 1) {
        speed.x = speed.x * 1.1;
        speed.y = speed.y * 1.1;
    }
    return (speed);
}