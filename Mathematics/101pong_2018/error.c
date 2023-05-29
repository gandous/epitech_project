/*
** EPITECH PROJECT, 2018
** 101pong | error.c
** File description:
** error.c
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void error_output(char const *str)
{
    write(2, str, strlen(str));
}

void print_info(void)
{
    printf("USAGE\n");
    printf("\t./101pong x0 y0 z0 x1 y1 z1 n\n");
    printf("\n");
    printf("DESCRIPTION\n");
    printf("\tx0 ball abscissa at time t - 1\n");
    printf("\ty0 ball ordinate at time t - 1\n");
    printf("\tz0 ball altitude at time t - 1\n");
    printf("\tx1 ball abscissa at time t\n");
    printf("\ty1 ball ordinate at time t\n");
    printf("\tz1 ball altitude at time t\n");
    printf("\tn time shift (greater than or equal to zero, integer)\n");
}

void is_number(char *str)
{
    for (int i = 0 ; str[i] != '\0' ; i += 1) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '.' && str[i] != '-') {
            printf("Arguments should only contains number, \"%c\" is not a number\n", str[i]);
            print_info();
            exit(84);
        }
    }
}

void only_number(int argc, char **argv)
{
    for (int i = 1 ; i < argc ; i += 1) {
        is_number(argv[i]);
    }
}