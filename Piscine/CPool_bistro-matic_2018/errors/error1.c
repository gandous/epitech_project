/*
** EPITECH PROJECT, 2018
** second part of errors
** File description:
** errors
*/

#include <stdlib.h>
#include "bistromatic.h"
#include "error.h"
#include "my.h"

void error_base(char *str)
{
    for (int i = 0 ; str[i] ; i++)
        if (str[i] < '0' || str[i] > '9') {
            my_putstr(SYNTAX_ERROR_MSG);
            exit (84);
    }
}

void invalid_expression(char *str, char *av)
{
    for (int i = 0 ; str[i] != '\0' ; i++)
        if ((str[i] < '0' || str[i] > '9') &&
            (str[i] != av[0] && str[i] != av[1] && str[i] != av[2] &&
             str[i] != av[3] && str[i] != av[4] && str[i] != av[5] && str[i] != av[6])) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit (84);
    }
}
