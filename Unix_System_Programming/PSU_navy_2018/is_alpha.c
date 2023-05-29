/*
** EPITECH PROJECT, 2019
** navy
** File description:
** Is string/char alpha (Navy format include)
*/

#include "navy.h"

int is_char_alpha_navy(char c)
{
    if (c < 'A' || c > 'H')
        return (FALSE);
    return (TRUE);
}
