/*
** EPITECH PROJECT, 2019
** 105torus_2018
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "105torus.h"
#include "my.h"

void print_usage(void)
{
    printf("USAGE\n");
    printf("    ./105torus opt a0 a1 a2 a3 a4 \n\n");
    printf("DESCRIPTION\n");
    printf("    opt       method option:\n");
    printf("                  1 for the bisection method\n");
    printf("                  2 for Newton’s method\n");
    printf("                  3 for the secant method\n");
    printf("    a[0-4]    coefficients of the equation\n");
    printf("    n         precision (the application of the polynomial to the solution should\n");
    printf("              be smaller than 10ˆ-n)\n");
}

int error_gestion(int ac, char **av)
{
    if (ac != 8)
        return (ERROR);
    if (atoi(av[1]) < 1 || atoi(av[1]) > 3)
        return (ERROR);
    if (atoi(av[7]) < 0)
        return (ERROR);
}

int main(int argc, char **argv)
{
    if (argc > 1) {
        if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
            print_usage();
            return (0);
        }
    }
    if (error_gestion(argc, argv) == ERROR)
        return (ERROR);
    if (argc != 8)
        return (84);
    return (torus(argc, argv));
}
