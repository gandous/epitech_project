/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** make_launch
*/

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include "minishell.h"

void display_status(int status)
{
    if (WIFSIGNALED(status)) {
        my_putstr(strsignal(WTERMSIG(status)));
        my_putchar('\n');
    }
}

int exec_with_arg(char *prog_name, char **argv, char **envp)
{
    int status = 0;
    pid_t cpid;
    pid_t w;

    cpid = fork();
    if (cpid == -1)
        return (84);
    if (cpid == 0) {
        if (execve(prog_name, argv, envp) == -1)
            perror("mysh");
        exit (127);
    } else {
        w = waitpid(cpid, &status,0);
        if (w == -1) {
            perror("waitpid");
            return (84);
        }
        display_status(status);
    }
    return (0);
}

int make_exec(char *arg, char ***envp)
{
    char *prog = get_first_word(arg);
    char **arguments = my_str_to_word_array(arg);
    int r_value = 0;

    r_value = exec_with_arg(prog, arguments, *envp);
    for (int i = 0 ; arguments[i] != NULL ; i += 1)
        free(arguments[i]);
    free(arguments);
    return (r_value);
}