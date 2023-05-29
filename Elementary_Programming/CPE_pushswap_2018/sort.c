/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** sort
*/

#include <stdlib.h>
#include <stdio.h>
#include "pushswap.h"

int check_sorted(my_list_t *list)
{
    int previous = list->val;

    if (list->next == NULL)
        return (1);
    while (list != NULL) {
        if (previous > list->val)
            return (-1);
        previous = list->val;
        list = list->next;
    }
    return (1);
}

int calc_size(long nb)
{
    char bin[LIST_SIZE];
    int size = 0;

    for (int i = 0 ; i < LIST_SIZE ; i += 1)
        bin[i] = '0';
    bin[LIST_SIZE] = '\0';
    if (nb < 0) {
        nb = nb * -1;
    }
    for (int i = LIST_SIZE - 1 ; nb != 0 ; nb /= 2, i -= 1)
        if (nb % 2 == 1)
            bin[i] = '1';
    for (int i = LIST_SIZE - 1 ; i >= 1 ; i -= 1)
        if (bin[i] == '1')
            size = LIST_SIZE - i;
    return (size);
}

int calc_list(my_list_t *list)
{
    int size = 0;

    while (list != NULL) {
        list = list->next;
        size += 1;
    }
    return (size);
}

void list_s(list_data_t *list, map_data_t map, print_t *d)
{
    int size = map.size;
    int index = map.index;
    my_list_t **list_a = (*list).list_a;
    my_list_t **list_b = (*list).list_b;


    for (int i = 0 ; i < size ; i += 1) {
        if ((*list_a)->value[index] == '1') {
            swap_to_last(list_a, (*list).end_a);
            add_to_buff(d, "ra ");
        } else {
            swap_list(list_a, list_b);
            add_to_buff(d, "pb ");
        }
    }
    while (*list_b != NULL) {
        swap_list(list_b, list_a);
        add_to_buff(d, "pa ");
    }
}

int sort(my_list_t *list_a, my_list_t *list_b, long max)
{
    list_data_t list = {&list_a, &list_b, NULL, NULL};
    int lenght = calc_size(max);
    int size = calc_list(list_a);
    map_data_t map_info;
    print_t *print_data = create_print_buff();

    for (my_list_t *temp = list_a ; temp->next != NULL ; temp = temp->next)
        list.end_a = &temp;
    list.end_b = &list_b;
    if (print_data == NULL)
        return (84);
    map_info.size = size;
    for (int i = LIST_SIZE - 1 ; i > LIST_SIZE - lenght - 1; i -= 1) {
        map_info.index = i;
        list_s(&list, map_info, print_data);
    }
    sort_neg(&list, size, print_data);
    display_buffer(print_data);
    free(print_data->buff);
    free(print_data);
    return (0);
}