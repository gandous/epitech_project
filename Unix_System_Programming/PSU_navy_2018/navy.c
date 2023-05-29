/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** navy
*/

#include <sys/types.h>
#include <stdlib.h>
#include "navy.h"

int navy(int argc, char **argv)
{
    char **map;
    pid_t pid_usr;

    if (error_gestion(argc, argv) == ERROR)
        return (ERROR);
    if (argc == 2) {
        if ((map = load_map(argv[1])) == NULL)
            return (ERROR);
    } else
        if ((map = load_map(argv[2])) == NULL)
            return (ERROR);
    if (connection(argc, argv, &pid_usr) == ERROR)
        return (ERROR);
    if (argc == 2)
        return (player_one_loop(pid_usr, map));
    else
        return (player_two_loop(pid_usr, map));
    return (SUCCESS);
}
