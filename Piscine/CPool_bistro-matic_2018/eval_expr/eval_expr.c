
/*
** EPITECH PROJECT, 2018
** eval_expr
** File description:
** calc gestion
*/

#include <stdlib.h>
#include "bistromatic.h"
#include "eval_expr.h"
#include "my.h"
#include "error.h"

char *parser(char *str)
{
    char *str_result;
    char *str_in_par;

    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] == '(') {
            str_in_par = parenthesis(str);
            str_result = sum_fac(str_in_par);
            str_in_par = put_par(str_in_par);
            str = str_postcalc(str, str_in_par, str_result);
            i = 0;
        }
    }
    str = sum_fac(str);
    return (str);
}

void errors(char *str, char **av)
{
    for (int i = 0 ; av[1][i] ; i++)
        error_id(av[1], i);
    for (int i = 0 ; av[2][i] ; i++)
        error_id(av[2], i);
    for (int i = 0 ; av[1][i] ; i++)
        error_operator_in_base(av[1], av[2], i);
    error_base(av[1]);
    error_parenthesis(str, av[2]);
    error_two_op_in_a_row(str, av[2]);
    error_begin_op(str, av[2]);
    invalid_expression(str, av[2]);
}

char *eval_expr(char const *base, char const *ops,
                char const *expr, unsigned int size)
{
    char *str = my_strcpy(expr);

    str = operators(str, ops);
    str = replace_sign(str);
    str = str_add(str);
    str = parser(str);
    if (str[0] == '-')
        str[0] = ops[3];
    if (str[0] == '+')
        str = str_cut(str);
    return (str);
}
