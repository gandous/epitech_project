/*
** EPITECH PROJECT, 2019
** 105torus_2018
** File description:
** method
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "my.h"

void print_value(double value, int n)
{
    char str[101];
    char val[101];
    char pres[20];

    sprintf(pres, "%%.%df\n", n);
    sprintf(val, pres, value);
    sprintf(str, "%.100f", value);
    for (int i = 100 ; str[i] == '0' ; i -= 1)
        val[i] = '\0';
    val[n + 2] = '\0';
    printf("x = %s\n", val);
}

void bisection(arg_t value, int n)
{
    double a = 0;
    double b = 1;
    double c = (a + b) / 2;
    double result = 0;
    int count = 0;

    while (fabs(solv_func(value, c)) > pow(10, -n)) {
        if (count++ == 100)
            exit(84);
        c = (a + b) / 2;
        result = solv_func(value, a) * solv_func(value, c);
        if (result >= 0)
            a = c;
        else
            b = c;
        print_value(c, n);
    }
}

void newton(arg_t value, int n)
{
    double x_n = 0.5;
    int count = 0;

    while (fabs(solv_func(value, x_n)) > pow(10, -n)) {
        if (count++ == 100)
            exit(84);
        print_value(x_n, n);
        x_n = x_n - (solv_func(value, x_n) / solv_deriv(value, x_n));
    }
    print_value(x_n, n);
}

void secant(arg_t value, int n)
{
    double x_0 = 0;
    double x_1 = 1;
    double x_2 = 0;
    int count = 0;

    while (fabs(solv_func(value, x_1)) > pow(10, -n)) {
        if (count++ == 100)
            exit(84);
        x_2 = x_1 - ((solv_func(value, x_1) * (x_1 - x_0)) / (solv_func(value, x_1) - solv_func(value, x_0)));
        x_0 = x_1;
        x_1 = x_2;
        print_value(x_2, n);
    }
}
