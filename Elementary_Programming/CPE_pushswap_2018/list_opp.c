/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** list opperation file
*/

#include <stdlib.h>
#include "pushswap.h"

void swap_first(my_list_t **first)
{
    my_list_t *sec = NULL;

    if ((*first)->next != NULL) {
        sec = (*first)->next;
        (*first)->next = sec->next;
        sec->next = *first;
        *first = sec;
    }
}

void swap_list(my_list_t **list_src, my_list_t **list_dest)
{
    my_list_t *temp = NULL;

    if (*list_src != NULL) {
        temp = (*list_src)->next;
        (*list_src)->next = *list_dest;
        *list_dest = *list_src;
        *list_src = temp;  
    }
}

void swap_to_last(my_list_t **list, my_list_t **last)
{
    my_list_t *save = *list;
    my_list_t *temp = *last;

    if (*last == NULL) {
        temp = *list;
        while (temp->next != NULL)
            temp = temp->next;
    }
    temp->next = save;
    *list = save->next;
    temp->next->next = NULL;
    *last = temp->next;
}

void swap_to_first(my_list_t **list)
{
    my_list_t *save = *list;
    my_list_t *temp = *list;

    while (temp->next != NULL) {
        if (temp->next->next == NULL)
            break;
        temp = temp->next;
    }
    save = temp->next;
    temp->next = NULL;
    save->next = *list;
    *list = save;
}