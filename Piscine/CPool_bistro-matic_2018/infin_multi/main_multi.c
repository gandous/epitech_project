/*
** EPITECH PROJECT, 2018
** execute multi
** File description:
** make multiplication
*/

#include <stdlib.h>
#include "my.h"
#include "infin.h"

char *infin_multi(char *nb1, char *nb2)
{
    int size1 = my_strlen(nb1);
    int size2 = my_strlen(nb2);
    char *result = NULL;
    int neg = 0;

    result = malloc(sizeof(char) * (size1 + size2 + 1));
    result = init_table(result, size1 + size2);
    size1 -= char_isneg(nb1);
    size2 -= char_isneg(nb2);
    if (char_isneg(nb2) == 0)
        neg = 1;
    for  (int i = 0 ; i < size2 ; i ++)
        result = calc_multi(nb1, nb2[size2 - i - neg] - '0',
        result , size1 + size2 - i);
    result[size1 + size2] = '\0';
    if (result_isnul(result, size1 + size2) == 1)
        return (calc_multinul(result));
    result = remove_zero(result, char_isneg(nb1) + char_isneg(nb2));
    return (result);
}
