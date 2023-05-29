/*
** EPITECH PROJECT, 2018
** display 
** File description:
** all func for display
*/

#include "my.h"
#include <stdio.h>

void display_velocity(coord_t *vector)
{
    printf("The velocity vector of the ball is:\n");
    printf("(%.2f, %.2f, %.2f)\n", vector->x, vector->y, vector->z);
}

void display_coord(coord_t *point, int time)
{
    printf("At time t + %d, ball coordinates will be:\n", time);
    printf("(%.2f, %.2f, %.2f)\n", point->x, point->y, point->z);
}

void display_point(coord_t *point)
{
    printf("x: %f, y: %f, z: %f\n", point->x, point->y, point->z);
}

void display_angle(float angle)
{
    printf("The incidence angle is:\n");
    printf("%.2f degrees\n", angle);
}

void display_fail(void)
{
    printf("The ball won’t reach the bat.\n");
}
