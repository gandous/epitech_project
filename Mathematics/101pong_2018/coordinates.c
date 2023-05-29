/*
** EPITECH PROJECT, 2018
** 101pong | coordinates
** File description:
** coordinates of the ball after a given amount of time
*/

#include "my.h"
#include <stdlib.h>
#include <math.h>

coord_t *ball_coordinates(coord_t *vector, coord_t *point2, float time)
{
    int t = 1;
    coord_t *ball = NULL;

    ball = malloc(sizeof(coord_t));
    if (ball == NULL)
        return (NULL);
    ball->x = point2->x + vector->x * time;
    ball->y = point2->y + vector->y * time;
    ball->z = point2->z + vector->z * time;
    return (ball);
}
