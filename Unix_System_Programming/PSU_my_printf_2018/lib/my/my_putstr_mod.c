/*
** EPITECH PROJECT, 2018
** my_put_str
** File description:
** print a char * and print non printable char with octal base
*/

#include "myprintf.h"

void octal_base(char const str)
{
    my_putchar('\\');
    my_putchar('0');
    if (str <= 7)
        my_putchar('0');
    print_base(str, 8, 0);
}

void my_putstr_mod(char const *str)
{
    for (int i = 0 ; str[i] != '\0' ; i += 1) {
        if (my_str_isprintable(str[i]) == -1) {
            octal_base(str[i]);
        } else {
            my_putchar(str[i]);
        }
    }
}
