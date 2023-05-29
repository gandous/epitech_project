/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** print a number
*/

#include "myprintf.h"

void my_put_nbr(long nb)
{
    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
}
