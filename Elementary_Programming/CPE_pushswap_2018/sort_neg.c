/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** sort_neg
*/

#include <stdio.h>
#include <stdlib.h>
#include "pushswap.h"

void sort_neg(list_data_t *list, int lenght, print_t *p)
{
    my_list_t **list_a = (*list).list_a;
    my_list_t **list_b = (*list).list_b;
    my_list_t **end_b = malloc(sizeof(my_list_t));

    *end_b = NULL;
    for (int i = 0 ; i < lenght ; i += 1) {
        if ((*list_a)->value[0] == '1') {
            swap_list(list_a, list_b);
            add_to_buff(p, "pb ");
            swap_to_last(list_b, end_b);
            add_to_buff(p, "rb ");
        } else {
            swap_to_last(list_a, (*list).end_a);
            add_to_buff(p, "ra ");
        }
    }
    while (*list_b != NULL) {
        swap_list(list_b, list_a);
        add_to_buff(p, "pa ");
    }
    free(end_b);
}