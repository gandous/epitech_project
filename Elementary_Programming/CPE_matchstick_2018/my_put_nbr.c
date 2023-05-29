/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** my_put_nbr
*/

#include <unistd.h>
#include "matchstick.h"

void my_put_nbr(int nb)
{
    if (nb < 0) {
        write(1, "-", 1);
    }
    if (nb > 9)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + '0');
}
