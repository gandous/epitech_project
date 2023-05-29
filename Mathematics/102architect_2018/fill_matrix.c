/*
** EPITECH PROJECT, 2018
** 102architect
** File description:
** fill the matrix during the process
*/

#include <stdlib.h>
#include <math.h>
#include "architect.h"

float **xy_matrix(char **av)
{
    float **matrix = create_matrix(3, 1);

    matrix[0][0] = atof(av[1]);
    matrix[1][0] = atof(av[2]);
    matrix[2][0] = 1;
    return (matrix);
}

float **translation_matrix(char **av, int *flag)
{
    float **matrix = create_matrix(3, 3);

    matrix[0][0] = 1;
    matrix[1][1] = 1;
    matrix[2][2] = 1;
    matrix[0][2] = atof(av[++*flag]);
    matrix[1][2] = atof(av[++*flag]);
    return (matrix);
}           

float **scaling_matrix(char **av, int *flag)
{
    float **matrix = create_matrix(3, 3);

    matrix[0][0] = atof(av[++*flag]);
    matrix[1][1] = atof(av[++*flag]);
    matrix[2][2] = 1;
    return (matrix);
}

float **rotation_matrix(char **av, int *flag)
{
    float angle = atof(av[++*flag]) * PI / 180;
    float **matrix = create_matrix(3, 3);

    matrix[0][0] = cos(angle);
    matrix[0][1] = -sin(angle);
    matrix[1][0] = sin(angle);
    matrix[1][1] = cos(angle);
    matrix[2][2] = 1;
    return (matrix);
}

float **reflection_matrix(char **av, int *flag)
{
    float angle = atof(av[++*flag]) * PI / 180;
    float **matrix = create_matrix(3, 3);

    matrix[0][0] = cos(2 * angle);
    matrix[0][1] = sin(2 * angle);
    matrix[1][0] = sin(2 * angle);
    matrix[1][1] = -cos(2 * angle);
    matrix[2][2] = 1;
    return (matrix);
}
