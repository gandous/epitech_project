/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** minishell
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "minishell.h"

int is_empty(char *str)
{
    for (int i = 0 ; str[i] != '\0' ; i += 1) {
        if (str[i] != ' ')
            return (-1);
    }
    return (0);
}

char *get_input(void)
{
    char *temp = NULL;
    size_t len = 0;

    if (isatty(0) == 1)
        my_putstr("$>");
    if (getline(&temp, &len, stdin) == -1) {
        if (isatty(0) == 1)
            my_putstr("exit\n");
        free(temp);
        return (NULL);
    }
    return (temp);
}

int select_operation(char ***envp, char *arg, my_func_t table[SIZE_FUNC])
{
    char *first_word = get_first_word(arg);
    int i = 0;
    int result = 0;

    if (first_word == NULL)
        return (84);
    if (is_empty(first_word) == 0)
        return (0);
    for ( ; i < SIZE_FUNC ; i += 1) {
        if (str_compare(first_word, table[i].name) == 0 || i == 6) {
            result = (table[i].func_ptr)(arg, envp);
            break;
        }
    }
    if (i == SIZE_FUNC && arg[0] != '\0') {
        my_putstr(first_word);
        my_putstr(": Command not found.\n");
    }
    free(first_word);
    return (result);
}

void handler1(int sig)
{
    if (isatty(0) == 1)
        my_putstr("\n$>");
}

int minishell(char **envp)
{
    char *input = NULL;
    char **my_env = NULL;
    my_func_t table[SIZE_FUNC] = {{&make_cd, "cd"}, {&make_env, "env"}, {&make_set_env, "setenv"}, {&make_unset_env, "unsetenv"}, {&make_exec, "./*"}, {&make_exit, "exit"}, {&make_default, ""}};

    my_env = copy_table(envp);
    signal(SIGINT, handler1);
    if (my_env == NULL)
        return (84);
    while ((input = get_input()) != NULL) {
        if (select_operation(&my_env, input, table) == -1)
            break;
        free(input);
    }
    for (int i = 0 ; my_env[i] != NULL ; i += 1)
        free(my_env[i]);
    free(my_env);
    return (0);
}
