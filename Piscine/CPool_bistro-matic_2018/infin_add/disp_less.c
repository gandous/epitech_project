/*
** EPITECH PROJECT, 2018
** disp_less
** File description:
** display '-'
*/

#include "my.h"

int cmp(char *str1, char *str2, int c)
{
    for (int i = 0 ; str1[i] != '\0' ; i++) {
        if (str1[i + 1] > str2[i] && c == 0)
            return (1);
        if (str1[i + 1] < str2[i] && c == 0)
            return (0);
        if (str1[i] < str2[i + 1] && c == 1)
            return (1);
        if (str1[i] + 1 > str2[i + 1] && c == 1)
            return (0);
    }
    return (0);
}

int fct_sorter(char *str1, char *str2, int i_ng)
{
    if (str1[0] == '-' && str2[0] == '-')
        return (++i_ng);
    if (str1[0] == '-')
        i_ng = 2;
    if (str2[0] == '-')
        i_ng = 3;
    return (i_ng);
}

char *sub(char *str1, char *str2, int diff1, int diff2)
{
    int i;
    int ii = 0;
    char *str;

    if (my_strlen(str1) - 1 == my_strlen(str2))
        ii++;
    if (my_strlen(str1) - 1 >= my_strlen(str2))
        str = str1;
    else str = str2;
    i = my_strlen(str) - 1;
    if ((my_strlen(str1) - 1 == my_strlen(str2)
        && cmp(str1, str2, 0) == 1) || my_strlen(str1) - 1 > my_strlen(str2))
        for (i ; str[i - diff1 - diff2 - 1] != '\0' ; i--)
            str[i] = str1[i - diff2] - str2[i - diff1 - 1] + 48;
    else
        for (i ; str[i - diff1 - diff2] != '\0' ; i--)
            str[i] = str2[i - ii - diff1] - str1[i - ii - diff2 + 1] + 48;
    return (str);
}
