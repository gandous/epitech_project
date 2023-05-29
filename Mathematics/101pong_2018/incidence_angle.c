/*
** EPITECH PROJECT, 2018
** Maths | 101pong
** File description:
** Angle d'incidence
*/

#include <math.h>
#include "my.h"
#include <stdio.h>

float get_angle(coord_t *vector)
{
    float norme;
    float angle;

    norme = get_norme(vector);
    angle = asin(fabs(vector->z) / fabs(norme));
    if (norme == 0)
        return (84);
    angle = angle * 180 / M_PI;
    return (angle);
}
