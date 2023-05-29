/*
** EPITECH PROJECT, 2018
** main div
** File description:
** main for division
*/

#include <stdlib.h>
#include "my.h"
#include "infin.h"

char *infin_div(char *nb1, char *nb2, char sign)
{
    char *result;
    int nb_sign = char_isneg(nb1) + char_isneg(nb2);

    nb1 = char_remove_sign(nb1);
    nb2 = char_remove_sign(nb2);
    if (char_issup(nb1, nb2) == 0) {
        result = malloc(sizeof(char) * 2);
        result[0] = '0';
        return (result);
    }
    result = malloc(sizeof(char) * (str_len(nb1) + 1));
    result = calc_div(nb1, nb2, sign);
    result = add_sign(result, nb_sign);
    return (result);
}
