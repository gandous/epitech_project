/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** my_ls
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_ls.h"

int my_ls(int argc, char **argv)
{
    int nb_file = 0;
    char *flag = check_flag(argc, argv, &nb_file);
    int dirpath = 0;

    if (nb_file >= 2)
        nb_file = 1;
    else
        nb_file = 0;
    for (int i = 1 ; i < argc ; i += 1) {
        if (argv[i][0] != '-') {
            make_ls(argv[i], flag, nb_file);
            dirpath = 1;
        }
    }
    if (dirpath == 0)
        make_ls(".", flag, 0);
    free(flag);
    return (0);
}