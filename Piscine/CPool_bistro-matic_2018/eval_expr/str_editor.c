/*
** EPITECH PROJECT, 2018
** str_editor
** File description:
** make or edit string for eval_expr
*/

#include <stdlib.h>
#include "eval_expr.h"
#include "my.h"

char *str_postcalc(char *str, char const *str_chg, char const *result)
{
    int i = 0;
    int ii = 0;
    char *rtrn;

    i = (my_strlen(str) + my_strlen(result) + 1);
    rtrn = malloc(sizeof(char *) * (i - my_strlen(str_chg)));
    for (i = 0 ; ii != my_strstr(str, str_chg) ; i++, ii++)
        rtrn[i] = str[i];
    for (int iii = 0 ; result[iii] != '\0' ; i++, iii++)
        rtrn[i] = result[iii];
    for (ii += my_strlen(str_chg) ; str[ii] != '\0' ; i++, ii++)
        rtrn[i] = str[ii];
    rtrn[i] = '\0';
    return (rtrn);
}

char *recup_calc1(char const *str, char sign)
{
    int i = 0;
    int min;
    int max;
    char malus_sign = sign;
    char *rtrn_str;

    for (max = 1; str[max] != sign ; max++);
    for (min = max - 1 ; str_isfac_sum(str, min) == 0 && str[min - 1] ; min--);
    str[min] == '-' ? i++ : i;
    min += i;
    str[min] == '+' ? i-- : i;
    rtrn_str = malloc(sizeof(char *) * (max - min + i + 1));
    rtrn_str[0] = '\0';
    for (i ; min < max ; i++, min++)
        rtrn_str[i] = str[min];
    if (!rtrn_str[0])
        rtrn_str[0] = '-';
    rtrn_str[i] = '\0';
    return (rtrn_str);
}

char *recup_calc2(char const *str, char sign)
{
    int i = 0;
    int min;
    int max;
    char malus_sign = sign;
    char *rtrn_str;

    sign == '+' ? malus_sign = '-' : malus_sign;
    for (min = 1 ; str[min] != sign && str[min] != malus_sign ; min++);
    str[++min] == '-' ? i = 1 : i;
    for (max = min + i ; str_isfac_sum(str, max + 1) == 0 && str[max + 1] ;
         max++);
    rtrn_str = malloc(sizeof(char *) * (max - min + 1));
    for (i = 0 ; min <= max ; i++, min++)
        rtrn_str[i] = str[min];
    rtrn_str[i] = '\0';
    return (rtrn_str);
}

char *str_glue(char const *str1, char sign, char const *str2)
{
    int size;
    int str_dpl = 0;
    char *rtrn_str;

    size = my_strlen(str1) + my_strlen(str2) + 2;
    rtrn_str = malloc(sizeof(char *) * size);
    for (int i = 0 ; str1[i] != 0 ; i++, str_dpl++)
        rtrn_str[str_dpl] = str1[i];
    rtrn_str[str_dpl++] = sign;
    for (int i = 0 ; str2[i] != 0 ; i++, str_dpl++)
        rtrn_str[str_dpl] = str2[i];
    rtrn_str[str_dpl] = '\0';
    return (rtrn_str);
}

char *str_add(char const *str)
{
    int i = 0;
    int ii = 1;
    char *rtrn_str;

    while (str[i++])
        if (str[i] == '-')
            ii++;
    rtrn_str = malloc(sizeof(char *) * (my_strlen(str) + ii));
    i = 0;
    ii = 0;
    rtrn_str[ii++] = str[i++];
    for (i ; str[i] ; i++, ii++) {
        if (my_isnum(str[i - 1]) == 1 && str[i] == '-')
            rtrn_str[ii++] = '+';
        rtrn_str[ii] = str[i];
    }
    rtrn_str[ii] = '\0';
    return (rtrn_str);
}
