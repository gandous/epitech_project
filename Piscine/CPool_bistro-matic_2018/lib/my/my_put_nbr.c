/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** displays number given as a parameter
*/
#include <unistd.h>

int my_putchar(char c);

int my_put_nbr(int nb)
{
    int n = 1;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    else if (nb == 0)
        my_putchar('0');
    while (nb/n != 0) {
        n = n * 10;
    }
    n = n / 10;
    while (n > 0) {
        my_putchar(nb/n + '0');
        nb = nb % n;
        n = n / 10;
    }
    return (0);
}
