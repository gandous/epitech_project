/*
** EPITECH PROJECT, 2018
** sum_fac
** File description:
** sum, * and / the string
*/

#include <stdlib.h>
#include "bistromatic.h"
#include "eval_expr.h"
#include "my.h"

char *infin_redirecting(char *str1, char *str2, char sign)
{
    char *str;

    if (sign == '*')
        str = infin_multi(str1, str2);
    if (sign == '/') {
        if (str2[0] == '0') {
            my_putstr(ERROR_MSG);
            exit (84);
        }
        str = infin_div(str1, str2, '/');
    }
    if (sign == '%') {
        if (str2[0] == '0')
            return (str1);
        str = infin_div(str1, str2, '%');
    }
    return (str);
}

char *factors(char *str)
{
    char *str1_to_calc;
    char *str2_to_calc;
    char *str_calc;
    char *result;

    for (int i = 0 ; str[i] ; i++) {
        if (str_isfac(str, i) == 1) {
            str1_to_calc = recup_calc1(str, str[i]);
            
            str2_to_calc = recup_calc2(str, str[i]);
            
            str_calc = str_glue(str1_to_calc, str[i], str2_to_calc);
            result = infin_redirecting(str1_to_calc, str2_to_calc, str[i]);
            str = str_postcalc(str, str_calc, result);
            i = 0;
        }
    }
    return (str);
}

char *summands(char *str)
{
    char *str1_to_calc;
    char *str2_to_calc;
    char *str_calc;
    char *result;

    for (int i = 0 ; str[i] ; i++) {
        if (str[i] == '+') {
            str1_to_calc = recup_calc1(str, '+');

            str2_to_calc = recup_calc2(str, '+');

            str_calc = str_glue(str1_to_calc, str[i], str2_to_calc);
            result = infin_add(str1_to_calc, str2_to_calc);
            str = str_postcalc(str, str_calc, result);
            i = 0;
        }
    }
    return (str);
}

char *sum_fac(char const *str)
{
    char *result = my_strcpy(str);

    result = factors(result);
    result = replace_sign(result);
    result = str_add(result);
    result = summands(result);
    return (result);
}
