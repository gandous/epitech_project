/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** function to transform arg in list
*/

#include <stdlib.h>
#include "pushswap.h"

int my_getnbr(char *str, long *size)
{
    int nb = 0;
    int i = 0;
    int neg = 1;

    if (str[i] == '-') {
        i += 1;
        neg *= -1;
    }
    for ( ; str[i] >= '0' && str[i] <= '9' ; i += 1) {
        nb += str[i] - '0';
        if (str[i + 1] != '\0')
            nb *= 10;
    }
    if (nb > *size)
        *size = nb;
    nb *= neg;
    return (nb);
}

char my_number(long nb)
{
    if (nb % 2 == 1) {
        return ('1');
    } else {
        return ('0');
    }
}

my_list_t *load_my_list(int argc, char **argv, long *size)
{
    my_list_t *list = NULL, *temp = NULL;
    long nb = 0;

    for (int i = argc - 1 ; i > 0 ; i -= 1) {
        temp = malloc(sizeof(my_list_t));
        nb = my_getnbr(argv[i], size);
        temp->val = nb;
        for (int i = 0 ; i < LIST_SIZE ; i += 1)
            temp->value[i] = '0';
        temp->value[LIST_SIZE] = '\0';
        if (nb < 0) {
            nb = nb * -1;
            temp->value[0] = '1';
        }
        for (int i = LIST_SIZE - 1 ; nb != 0 ; nb /= 2, i -= 1)
            temp->value[i] = my_number(nb);
        temp->next = list;
        list = temp;
    }
    return (list);
}

void del_list(my_list_t *list)
{
    my_list_t *temp = NULL;

    while (list != NULL) {
        temp = list->next;
        free(list);
        list = temp;
    }
}