/*
** EPITECH PROJECT, 2018
** compatibility
** File description:
** make infin_add return a char * without bug
*/

#include <stdlib.h>
#include "my.h"

char *put_one(char const *str, int i_ng)
{
    int i = 0;
    char *rtrn;

    rtrn = malloc(sizeof(char *) * (my_strlen(str) + 1));
    if (i_ng == 1)
        rtrn[i++] = str[0];
    rtrn[i++] = '1';
    for (i_ng ; str[i_ng] ; i_ng++, i++)
        rtrn[i] = str[i_ng];
    rtrn[i] = '\0';
    return (rtrn);
}

char *hide_malus(char *str, int malus)
{
    char *rtrn;
    int i;

    if (malus == 1) {
        rtrn = malloc(sizeof(char *) * my_strlen(str));
        for (i = 0 ; str[i + 1] ; i++)
            rtrn[i] = str[i + 1];
        rtrn[i] = '\0';
        return (rtrn);
    }
    return (str);
}

char *show_malus(char *str, int malus)
{
    char *rtrn;
    int i = 0;

    if (malus == 1) {
        rtrn = malloc(sizeof(char *) * (my_strlen(str) + 1));
        rtrn[i] = '-';
        while (str[i])
            rtrn[++i] = str[i];
        rtrn[++i] = '\0';
        return (rtrn);
    }
    return (str);
}

char *delete_useless0(char *str)
{
    char *rtrn;
    int i = 0;
    int ii = 0;

    if (str[0] == '0') {
        for (i ; str[i] == '0' ; i++);
        rtrn = malloc(sizeof(char *) * (my_strlen(str) - i + 2));
        for (i ; str[i] ; i++, ii++)
            rtrn[ii] = str[i];
        if (ii == 0)
            rtrn[ii++] = '0';
        rtrn[ii] = '\0';
        return (rtrn);
    }
    return (str);
}
