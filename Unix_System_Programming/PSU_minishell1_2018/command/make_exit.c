/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** make_exit
*/

#include <stdlib.h>
#include "minishell.h"

int make_exit(char *arg, char ***envp)
{
    int nb = 0;
    char **str = my_str_to_word_array(arg);
    int size = 0;

    if (str == NULL)
        return (84);
        size = count_size_array(str);
    if (size == 1) {
        my_putstr("exit\n");
        exit (0);
    } else if (size == 2) {
        if (is_number(str[1]) == 0) {
            nb = my_getnbr(str[1]);
            my_putstr("exit\n");
            exit (nb);
        }
    }
    my_putstr("exit: Expression Syntax.\n");
    return (0);
}