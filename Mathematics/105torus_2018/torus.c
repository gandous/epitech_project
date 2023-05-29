/*
** EPITECH PROJECT, 2019
** 105torus_2018
** File description:
** torus
*/

#include <math.h>
#include <stdlib.h>
#include "my.h"

int torus(int argc, char **argv)
{
    arg_t value;
    int opt = atoi(argv[1]);
    int n = atoi(argv[7]);

    if (opt < 1 || opt > 3)
        return (84);
    value.a0 = atof(argv[2]);
    value.a1 = atof(argv[3]);
    value.a2 = atof(argv[4]);
    value.a3 = atof(argv[5]);
    value.a4 = atof(argv[6]);
    if (opt == 1)
        bisection(value, n);
    else if (opt == 2)
        newton(value, n);
    else
        secant(value, n);
}