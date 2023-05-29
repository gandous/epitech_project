/*
** EPITECH PROJECT, 2018
** calcule
** File description:
** calcule
*/

#include <stdlib.h>
#include "my.h"
#include "infin.h"

int calcul_retenu(int *nb)
{
    int retenu = 0;

    while (*nb > 9) {
        *nb -= 10;
        retenu += 1;
    }
    return (retenu);
}

char *calc_multinul(char *result)
{
    result[0] = '0';
    result[1] = '\0';
    return (result);
}

char *calc_multi(char *nb1, int nb2,char *result, long total_size)
{
    int nb_temp = 0;
    int retenu_multi = 0;
    int retenu_add = 0;
    int index = my_strlen(nb1) - 1;
    int i;

    for (i = total_size - 1 ; i >= total_size - my_strlen(nb1) +
        char_isneg(nb1) ; i -= 1) {
        nb_temp = (nb1[index] - '0') * nb2 + retenu_multi;
        retenu_multi = 0;
        retenu_multi = calcul_retenu(&nb_temp);
        nb_temp += ((result[i] - '0') +  retenu_add);
        retenu_add = 0;
        retenu_add = calcul_retenu(&nb_temp);
        result[i] = nb_temp + '0';
        index -= 1;
    }
    result[i] += (retenu_add + retenu_multi);
    return (result);
}
