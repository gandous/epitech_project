/*
** EPITECH PROJECT, 2019
** 105torus_2018
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

typedef struct arg_s {
    double a0;
    double a1;
    double a2;
    double a3;
    double a4;
    double x;
} arg_t;

typedef struct interval_s {
    double start;
    double end;
} interval_t;

int torus(int argc, char **argv);
void bisection(arg_t value, int n);
double solv_func(arg_t arg, double x);
double solv_deriv(arg_t arg, double x);
void newton(arg_t value, int n);
void secant(arg_t value, int n);

#endif
