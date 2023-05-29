/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** make_env
*/

#include <stdlib.h>
#include "minishell.h"

int make_env(char *arg, char ***envp)
{
    for (int i = 0 ; (*envp)[i] != NULL ; i += 1) {
        my_putstr((*envp)[i]);
        my_putchar('\n');
    }
}

int set_my_var(char **s, char ***envp)
{
    char *temp = NULL;

    if (is_alpha(s[1]) == -1) {
        my_putstr("setenv: Variable name must ");
        my_putstr("contain alphanumeric characters.\n");
        return (84);
    }
    temp = conc_env_name(s[1], s[2]);
    if (temp == NULL)
        return (84);
    *envp = add_to_array(*envp, temp);
    return (0);
}

int make_set_env(char *arg, char ***envp)
{
    char **s = my_str_to_word_array(arg);
    int size = 0;
    int result = 0;

    if (s == NULL)
        return (84);
    for (int i = 0 ; s[i] != NULL ; i += 1, size += 1);
    if (size == 1) {
        make_env(arg, envp);
        return (0);
    }
    if (s[1][0] < 'A' || (s[1][0] > 'Z' && s[1][0] < 'a') || s[1][0] > 'z') {
        my_putstr("setenv: Variable name must begin with a letter.\n");
        return (84);
    }
    result = set_my_var(s, envp);
    for (int i = 0 ; s[i] != NULL ; i += 1)
        free(s[i]);
    free(s);
    return (result);
}

int make_unset_env(char *arg, char ***envp)
{
    char **str = my_str_to_word_array(arg);
    int size = 0;

    if (str == NULL)
        return (84);
    for (int i = 0 ; str[i] != NULL ; i +=1, size += 1);
    if (size == 1) {
        my_putstr("unsetenv: Too few arguments.\n");
        return (0);
    }
    *envp = remove_from_array(str[1], *envp);
    for (int i = 0 ; str[i] != NULL ; i += 1)
        free(str[i]);
    free(str);
    return (0);
}