/*
** EPITECH PROJECT, 2019
** navy
** File description:
** Error gestion
*/

#include "navy.h"

int error_gestion(int ac, char **av)
{
    if (ac != 2 && ac != 3)
        return (ERROR);
    if (ac == 3) {
        if (is_nbr_positif(av[1]) == FALSE)
            return (ERROR);
        if (is_navy_file(av[2]) == FALSE)
            return (ERROR);
    } else
        if (is_navy_file(av[1]) == FALSE)
            return (ERROR);
    return (SUCCESS);
}
