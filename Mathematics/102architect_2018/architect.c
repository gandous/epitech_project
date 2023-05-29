/*
** EPITECH PROJECT, 2018
** 102 archtitect
** File description:
** main function for calc matrix
*/

#include <stdlib.h>
#include <stdio.h>
#include "architect.h"

float **switch_matrix(char **av, int *index)
{
    switch (av[*index][1]) {
    case 't':
        printf("Translation along vector (%s, %s)\n", av[*index + 1], av[*index + 2]);
        return (translation_matrix(av, index));
    case 'z':
        printf("Scaling by factors %s and %s\n", av[*index + 1], av[*index + 2]);
        return (scaling_matrix(av, index));
    case 'r':
        printf("Rotation by a %s degree angle\n", av[*index + 1], av[*index + 2]);
        return (rotation_matrix(av, index));
    case 's':
        printf("Reflection over an axis with an inclination angle of %s degrees\n", av[*index + 1], av[*index + 2]);
        return (reflection_matrix(av, index));
    }
}

void architect(int ac, char **av)
{
    int index = 3;
    float **matrix1 = switch_matrix(av, &index);
    float **matrix2 = NULL;

    index += 1;
    while (index < ac) {
        matrix2 = switch_matrix(av, &index);
        matrix1 = calc_matrix(matrix2, matrix1);
        index += 1;
    }
    display_matrix(matrix1);
    matrix2 = xy_matrix(av);
    matrix1 = calc_matrix_final(matrix1, matrix2);
    display_result(atof(av[1]), atof(av[2]), matrix1[0][0], matrix1[1][0]);
}