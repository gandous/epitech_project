/*
** EPITECH PROJECT, 2018
** parenthesis
** File description:
** new version of parenthesis
*/

#include <stdlib.h>
#include "eval_expr.h"
#include "my.h"

char *cpy_parenthesis(char *dest, char *str, int begin)
{
    int i;
    int j = 0;

    for (i = begin ; str[i] != ')' ; i++) {
        dest[j] = str[i];
        j++;
    }
    dest[j] = '\0';
    return (dest);
}

char *parenthesis(char *str)
{
    int total_size;
    int begin = 0;
    char *dest = NULL;

    total_size = my_strlen(str) + 1;
    dest = (char *)malloc(sizeof(char) * total_size);
    for (int i = 0 ; str[i] != ')' ; i++) {
        if (str[i] == '(')
            begin = i + 1;
    }
    dest = cpy_parenthesis(dest, str, begin);
    return (dest);
}

char *put_par(char const *str)
{
    char *rtrn_str;
    int i;

    rtrn_str = malloc(sizeof(char*) * (my_strlen(str) + 3));
    rtrn_str[0] = '(';
    for (i = 0 ; str[i] ; i++)
        rtrn_str[i + 1] = str[i];
    rtrn_str[++i] = ')';
    rtrn_str[++i] = '\0';
    return (rtrn_str);
}
