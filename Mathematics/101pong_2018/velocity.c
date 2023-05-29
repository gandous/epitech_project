/*
** EPITECH PROJECT, 2018
** Maths | velocity
** File description:
** velocity
*/

#include <math.h>
#include "my.h"
#include <stdlib.h>

coord_t *get_velocity(coord_t *point, coord_t *point2)
{
    coord_t *vector = NULL;

    vector = malloc(sizeof(coord_t));
    if (vector == NULL)
        return (NULL);
    vector->x = point2->x - point->x;
    vector->y = point2->y - point->y;
    vector->z = point2->z - point->z;
    return (vector);
}

float get_norme(coord_t *vector)
{
    float norme;

    norme = sqrt(pow(vector->x, 2) + pow(vector->y, 2) + pow(vector->z, 2));
    if (norme < 0)
        return (84);
    return (norme);
}
