/*
** EPITECH PROJECT, 2018
** architect
** File description:
** error gstion for architect
*/

#include <stdlib.h>
#include "architect.h"

int is_number(char *nbr)
{
    for (int i = 0 ; nbr[i] != '\0' ; i += 1) {
        if ((nbr[i] < '0' || nbr[i] > '9') && nbr[i] != '.' && nbr[i] != '-')
            return (ERROR); 
    }
    return (SUCCESS);
}

int is_compatible(char *flag)
{
    if (flag[0] != '-' || flag[2] != '\0')
        exit(84);
    switch (flag[1]) {
    case 't':
        return (3);
    case 'z':
        return (3);
    case 'r':
        return (2);
    case 's':
        return (2);
    default:
        exit(84);
    }
}

int error_gestion(int ac, char **av)
{
    int next_flag = 3;
    
    if (ac < 5)
        return (ERROR);
    for (int i = 1 ; i < ac ; i++) {
        if (i == next_flag)
            next_flag += is_compatible(av[i]);
        else if (is_number(av[i]) == ERROR)
            return (ERROR);
        if (i + 1 == next_flag && ac == next_flag)
            return (SUCCESS);
    }
    return (ERROR);
}
