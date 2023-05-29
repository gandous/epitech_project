/*
** EPITECH PROJECT, 2018
** infin_add
** File description:
** none
*/

#include <stdlib.h>
#include "infin.h"
#include "my.h"

char *deduction_sub(char *str)
{
    for (int i = my_strlen(str) - 1 ; i >= 0 ; i--) {
        if (str[i] < '0') {
            str[i] += 10;
            str[i - 1]--;
        }
    }
    return (str);
}

char *substraction(char *str1, char *str2, int i_ng)
{
    char *str;
    int diff1 = 0;
    int diff2 = 0;
    int malus = 0;

    if (my_strlen(str1) - 1 >= my_strlen(str2)) {
        diff1 = my_strlen(str1) - my_strlen(str2) - 1;
        i_ng++;
    } else
        diff2 = my_strlen(str2) - my_strlen(str1) + 1;
    str = sub(str1, str2, diff1, diff2);
    if (my_isnum(str[0]) == 0 && str[0] != '-')
        str = str_cut(str);
    str[0] == '-' ? malus++ : malus;
    str = hide_malus(str, malus);
    str = deduction_sub(str);
    str = delete_useless0(str);
    str = show_malus(str, malus);
    return (str);
}

char *deduction_add(char *str, int i_ng)
{
    for (int i = my_strlen(str) - 1 ; i - i_ng >= 0 ; i--) {
        if (str[i] > '9' && (str[i - i_ng - 1]) == '\0') {
            str[i] -= 10;
            str = put_one(str, i_ng);
        } else if (str[i] > '9') {
            str[i] -= 10;
            str[i - 1]++;
        }
    }
    return (str);
}

char *addition(char *str1, char *str2, int i_ng)
{
    char *str;
    int i;
    int diff1 = 0;
    int diff2 = 0;

    if (my_strlen(str1) > my_strlen(str2)) {
        str = str1;
        diff1 = my_strlen(str1) - my_strlen(str2);
    } else {
        str = str2;
        diff2 = my_strlen(str2) - my_strlen(str1);
    }
    i = my_strlen(str) - 1;
    for (i ; str1[i - i_ng - diff2] != 0 && str2[i - i_ng - diff1] != 0 ;
        i--) {
        str[i] = str1[i - diff2] + str2[i - diff1] - 48;
    }
    str = deduction_add(str, i_ng);
    return (str);
}

char *infin_add(char *str1, char *str2)
{
    int i_ng = 0;
    char *str;

    i_ng = fct_sorter(str1, str2, i_ng);
    if (i_ng == 2)
        str = substraction(str1, str2, 0);
    else if (i_ng == 3)
        str = substraction(str2, str1, 0);
    else
        str = addition(str1, str2, i_ng);
    return (str);
}
