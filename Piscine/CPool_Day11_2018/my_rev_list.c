/*
** EPITECH PROJECT, 2018
** rev list
** File description:
** reverse list
*/

#include <stdlib.h>
#include "mylist.h"

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *current;
    linked_list_t *next;
    linked_list_t *prev;

    current = *begin;
    next = NULL;
    prev = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *begin = prev;
}
