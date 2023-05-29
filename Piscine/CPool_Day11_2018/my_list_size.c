/*
** EPITECH PROJECT, 2018
** list size
** File description:
** return list size
*/

#include  <stdlib.h>
#include "mylist.h"

int my_list_size(linked_list_t const *begin)
{
    linked_list_t *temp = begin;
    int count = 0;

    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    return (count);
}
