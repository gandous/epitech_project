/*
** EPITECH PROJECT, 2018
** print basr
** File description:
** convert and print a number from base 10 to any base
*/

#include "myprintf.h"

void print_base(unsigned long long nbr, int base, int maj)
{
    unsigned long long result = nbr / base;
    char disp_char[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'a', 'b', 'c', 'd', 'e', 'f'};

    if (result != 0)
        print_base(result, base, maj);
    if (maj == 1 && disp_char[(nbr % base)] >= 'a')
        maj = 32;
    else
        maj = 0;
    my_putchar(disp_char[(nbr % base)] - maj);
}
