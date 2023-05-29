/*
** EPITECH PROJECT, 2018
** calcule div number sup
** File description:
** search sup nbr
*/

#include <stdlib.h>
#include "infin.h"
#include "my.h"
#include "eval_expr.h"

char *char_to_neg(char *nbr)
{
    char *neg = NULL;

    neg = malloc(sizeof(char) * (my_strlen(nbr) + 2));
    for (int index = 0 ; nbr[index] != '\0' ; index += 1) {
        neg[index + 1] = nbr[index];
    }
    neg[0] = '-';
    neg[my_strlen(nbr) + 1] = '\0';
    return (neg);
}

char *calc_modulo(char *nb1, char *nb2, char *result)
{
    char *temp = NULL;

    temp = infin_multi(nb2, result);
    temp = infin_add(char_to_neg(temp), nb1);
    return (temp);
}

char *calc_sup_div(char *nb1,char *nb2, char *pas, char *begin)
{
    char *temp = NULL;
    char *pas_copy = NULL;
    char malus_un[3] = "-1";

    temp = nb2;
    pas_copy = malloc(sizeof(char) * (my_strlen(pas) + 1));
    pas_copy = my_strcpy(begin);
    while (char_issup(temp, nb1) == 0) {
        temp = infin_multi(nb2, pas_copy);
        pas_copy = infin_add(pas, pas_copy);
    }
    if (my_strlen(pas) > 1)
        pas_copy = infin_add(char_to_neg(pas), pas_copy);
    temp = infin_add(char_to_neg(pas), pas_copy);
    if (*calc_modulo(nb1, nb2, temp) != '0')
        temp = infin_add(temp, malus_un);
    return (temp);
}
