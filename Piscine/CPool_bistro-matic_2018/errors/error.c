/*
** EPITECH PROJECT, 2018
** error 
** File description:
** errors gestion
*/

#include <stdlib.h>
#include "bistromatic.h"
#include "error.h"
#include "my.h"

void error_parenthesis(char *str, char const *operator)
{
    int i = 0;

    for (int k = 0 ; str[k] ; k++) {
	if (str[k] == operator[0])
            i++;
        else if (str[k] == operator[1])
            i--;
        if (i < 0) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(84);
	}
    }
    if (i == 0)
        return;
    if (i != 0) {
        my_putstr(SYNTAX_ERROR_MSG);
	exit(84);
    }
}

void error_id(char *str, int i)
{
    for (int j = i + 1 ; str[j] ; j++)
        if (str[i] == str[j]) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit (84);
        }
}

void error_operator_in_base(char *str, char *stb, int i)
{
    for (int j = 0 ; stb[j] ; j++)
        if (str[i] == stb[j]) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit (84);
        }
}

void error_two_op_in_a_row(char *str, char *stb)
{
    int i = 0;
    
    for (int i = 0 ; str[i] ; i++)
        if ((str[i] == stb[5] || str[i] == stb[4] || str[i] == stb[6] || str[i] == stb[0])
            && (str[i + 1] == stb[4] || str[i + 1] == stb[5] || str[i + 1] == stb[6] ||
                str[i + 1] == ('\0'))) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit (84);
    }
}

void error_begin_op(char *str, char *stb)
{
    if (str[0] == stb[1] || str[0] == stb[2] || str[0] == stb[4] ||
        str[0] == stb[5] || str[0] == stb[6]) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(84);
    }
}
