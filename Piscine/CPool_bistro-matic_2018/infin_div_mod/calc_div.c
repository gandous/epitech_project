/*
** EPITECH PROJECT, 2018
** calc div
** File description:
** calc div
*/

#include <stdlib.h>
#include "infin.h"
#include "my.h"

char *generate_pas(char *nbr)
{
    int size = my_strlen(nbr);
    char *pas = NULL;

    pas = malloc(sizeof(char) + (size + 1));
    pas[0] = '1';
    for (int i = 1 ; i < size; i += 1)
        pas[i] = '0';
    pas[size] = '\0';
    return (pas);
}

char *add_sign(char *nbr, int count)
{
    int size = my_strlen(nbr);
    char *temp = NULL;

    if (count % 2 == 1) {
        temp = malloc(sizeof(char) * (size + 2));
        temp[0] = '-';
        temp[size + 1] = '\0';
        for (int i = 0 ; i < size ; i += 1)
            temp[i + 1] = nbr[i];
        return (temp);
    }
    return (nbr);
}

char *create_zero(void)
{
    char *temp;

    temp = malloc(sizeof(char) * 2);
    temp[0] = '1';
    return (temp);
}

char *calc_div(char *nb1, char *nb2, char sign)
{
    char *sup = NULL;
    char *pas = NULL;

    if (str_finder(nb1, nb2) == 1)
        return (create_zero());
    pas = generate_pas(nb1);
    sup = malloc(sizeof(char) * (my_strlen(nb2) + 1));
    sup = pas;
    while (my_strlen(pas) > 1) {
        sup = calc_sup_div(nb1, nb2, pas, sup);
        pas[my_strlen(pas) - 1] = '\0';
    }
    sup = calc_sup_div(nb1, nb2, pas, sup);
    if (sign == '%')
        return (calc_modulo(nb1, nb2, sup));
    return (sup);
}
