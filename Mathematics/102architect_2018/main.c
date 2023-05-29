/*
** EPITECH PROJECT, 2018
** 102architect
** File description:
** main
*/

#include <stdlib.h>
#include "architect.h"

int main(int ac, char **av)
{
    if (ac < 2)
        return (ERROR);
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        return (usage(SUCCESS));
    if (error_gestion(ac, av) == ERROR)
        return (ERROR);
    architect(ac, av);
    return (SUCCESS);
}
