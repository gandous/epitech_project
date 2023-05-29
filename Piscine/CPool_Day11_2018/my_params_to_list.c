/*
** EPITECH PROJECT, 2018
** my param to list
** File description:
** my param to list
*/


#include <stdlib.h>
#include "mylist.h"

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *tmp;

    tmp = NULL;
    for (int i = 0 ; i < ac ; i++) {
        linked_list_t *temp2;
        temp2 = malloc(sizeof(linked_list_t));
        temp2->data = av[i];
        temp2->next = tmp;
        tmp = temp2;
    }
    return (tmp);
}
