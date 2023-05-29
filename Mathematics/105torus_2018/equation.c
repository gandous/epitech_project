/*
** EPITECH PROJECT, 2019
** 105torus_2018
** File description:
** equation
*/

#include <math.h>
#include "my.h"

double solv_func(arg_t arg, double x)
{
    double result = 0;

    result = arg.a4 * pow(x, 4) + arg.a3 * pow(x, 3) + arg.a2 * pow(x, 2) + arg.a1 * x + arg.a0;
    return (result);
}

double solv_deriv(arg_t arg, double x)
{
    double result = 0;

    result = 4 * arg.a4 * pow(x, 3) + 3 * arg.a3 * pow(x, 2) + 2 * arg.a2 * x + arg.a1;
    return (result);
}