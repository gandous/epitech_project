/*
** EPITECH PROJECT, 2019
** navy
** File description:
** Is number/digit (navy format include)
*/

#include "navy.h"

int is_digit_navy(char c)
{
    if (c < '1' || c > '8')
        return (FALSE);
    return (TRUE);
}

int is_nbr_positif(char *str)
{
    for (int i = 0 ; str[i] ; i++)
        if (str[i] < '0' || str[i] > '9')
            return (FALSE);
    return (TRUE);
}
