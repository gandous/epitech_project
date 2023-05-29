/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** copy of the function printf
*/

#include <unistd.h>
#include <stdarg.h>
#include "myprintf.h"

int display(va_list ap, int index, char const *str)
{
    switch (str[index]) {
    case 'i':
        my_put_nbr(va_arg(ap, int));
        break;
    case 'd':
        my_put_nbr(va_arg(ap, int));
        break;
    case 's':
        my_putstr(va_arg(ap, char *));
        break;
    case 'S':
        my_putstr_mod(va_arg(ap, char *));
        break;
    case 'c':
        my_putchar((char)va_arg(ap, int));
        break;
    case 'x':
        print_base(va_arg(ap, int), 16, 0);
        break;
    case 'X':
        print_base(va_arg(ap, int), 16, 1);
        break;
    case 'b':
        print_base(va_arg(ap, int), 2, 0);
        break;
    case 'p':
        my_putstr("0x");
        print_base(va_arg(ap, unsigned long long), 16, 0);
        break;
    case 'u':
        my_put_nbr(va_arg(ap, unsigned int));
        break;
    case 'o':
        print_base(va_arg(ap, int), 8, 0);
        break;
    case 'l':
        if (str[index + 1] == 'd') {
            my_put_nbr(va_arg(ap, long));
            return (index + 1);
        }
        break;
    }
    return (index);
}

int my_printf(char const *str, ...)
{
    va_list ap;

    va_start(ap, str);
    for (int i = 0 ; str[i] != '\0' ; i += 1) {
        if (str[i] == '%') {
            i = display(ap, i + 1, str);
        } else {
            my_putchar(str[i]);
        }
    }
    va_end(ap);
    return (0);
}
