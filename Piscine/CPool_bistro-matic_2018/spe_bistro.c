/*
** EPITECH PROJECT, 2018
** operators
** File description:
** operators
*/

#include <stdlib.h>
#include "bistromatic.h"
#include "my.h"

int descriptor(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && !av[1][2]) {
        my_putstr("USAGE\n./calc base operators size_read\n\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("- base: all the symbols of the base\n");
        my_putstr("- operators: the symbols for the ");
        my_putstr("parentheses and the 5 operators\n");
        my_putstr("- size_read: number of characters to be read");
        my_putchar('\n');
        return (1);
    }
    return (0);
}

char *operators(char *str, char const *operator)
{
    for (int i = 0 ; str[i] ; i++) {
        str[i] == operator[0] ? str[i] = '(' : 0;
        str[i] == operator[1] ? str[i] = ')' : 0;
        str[i] == operator[2] ? str[i] = '+' : 0;
        str[i] == operator[3] ? str[i] = '-' : 0;
        str[i] == operator[4] ? str[i] = '*' : 0;
        str[i] == operator[5] ? str[i] = '/' : 0;
        str[i] == operator[6] ? str[i] = '%' : 0;
    }
    return (str);
}

char *replace_with(char *str, char sign, int start, int end)
{
    char *temp = NULL;
    int index = 0;

    temp = malloc(sizeof(char) * (my_strlen(str) - (start - end) + 1));
    for (int i = 0 ; i <= end ; i += 1){
        temp[i] = str[i];
    }
    temp[end + 1] = sign;
    index = end + 2;
    for (int i = start + 1 ; str[i] != '\0' ; i += 1) {
        temp[index] = str[i];
        index += 1;
    }
    return (temp);
}

char *count_sign(char *str, int index) {
    int less = 0;
    int plus = 0;
    int i;

    for (i = index ; (str[i] == '+' || str[i] == '-') && i < 20 ; i -= 1) {
        if (str[i] == '+')
            plus += 1;
        if (str[i] == '-')
            less += 1;
    }
    if (plus + less == 1)
        return (str);
    if (less % 2 == 0)
        return (replace_with(str, '+', index, i));
    else
        return (replace_with(str, '-', index, i));
}

char *replace_sign(char *str)
{
    char *temp = NULL;

    temp = my_strcpy(str);
    for (int index = my_strlen(str) - 1 ; index >= 0 ; index -= 1) {
        if (str[index] == '+' || str[index] == '-') {
            temp = count_sign(temp, index);
        }
        while (str[index] == '+' || str[index] == '-') {
            index -= 1;
        }
    }
    free(str);
    return (temp);
}
