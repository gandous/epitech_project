/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** main push swap
*/

#include <stdlib.h>
#include <stdio.h>
#include "pushswap.h"

int pushswap(int argc, char **argv)
{
    long size = 0;
    my_list_t *list = load_my_list(argc, argv, &size);
    my_list_t *temp = NULL;
    int output = 0;

    if (check_sorted(list) == 1) {
        my_putstr("\n", 1);
        del_list(list);
        return (0);
    }
    output = sort(list, temp, size);
    del_list(list);
    del_list(temp);
    return (output);
}