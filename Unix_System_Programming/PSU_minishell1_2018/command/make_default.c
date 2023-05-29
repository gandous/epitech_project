/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** make_default
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

char *get_one_path_line(char *line, int *index)
{
    int i = *index;
    char *temp = NULL;
    int size = 0;

    if (line[i] == ':' || line[i] == '=')
        i++;
    for (int x = i ; line[x] != ':' && line[x] != '\0' ; x++, size++);
    if ((temp = malloc(sizeof(char) * (size + 1))) == NULL)
        return (NULL);
    temp[size] = '\0';
    for (int x = 0 ; line[i] != ':' && line[i] != '\0' ; x++, i++)
        temp[x] = line[i];
    *index = i;
    return (temp);
}

char **get_all_path(char **envp, char *name)
{
    char **temp = NULL;
    int i = 0;
    int path_nb = 0;
    int start = 0;

    for ( ; envp[i] != NULL && compare_var(envp[i], "PATH") ; i += 1);
    if (envp[i] == NULL)
        return (NULL);
    for (int x = 0 ; envp[i][x] != '\0' ; x += 1)
        if (envp[i][x] == ':' || envp[i][x] == '=')
            path_nb++;
    if ((temp = malloc(sizeof(char *) * (path_nb + 1))) == NULL)
        return (NULL);
    for (int g = 0 ; g <= path_nb ; g += 1)
        temp[g] = NULL;
    for ( ; envp[i][start] != '=' && envp[i][start] != '\0' ; start += 1);
    start++;
    for (int index = 0 ; envp[i][start] != '\0' ; index += 1)
        temp[index] = get_one_path_line(envp[i], &start);
    return (temp);
}

char *get_exec_path(char **all_path, char *prog_name)
{
    struct stat sb;
    char *temp_path = NULL;
    int i = 0;

    for ( ; all_path[i] != NULL ; i++) {
        temp_path = create_dirpath(all_path[i], prog_name);
        if (stat(temp_path, &sb) != -1)
            break;
        free(temp_path);
    }
    if (all_path[i] != NULL) {
        return (temp_path);
    } else if (stat(prog_name, &sb) != -1) {
        return (my_strcpy(prog_name));
    }
    my_putstr(prog_name);
    my_putstr(": Command not found.\n");
    return (NULL);
}

void free_default_table(char **all_path, char **arguments)
{
    for (int i = 0 ; all_path[i] != NULL ; i += 1)
        free(all_path[i]);
    free(all_path);
    for (int i = 0 ; arguments[i] != NULL ; i += 1)
        free(arguments[i]);
    free(arguments);
}

int make_default(char *arg, char ***envp)
{
    char **all_path = NULL;
    char *prog_name = get_first_word(arg);
    char *exec_file = NULL;
    char **arguments = my_str_to_word_array(arg);
    
    if (prog_name == NULL || arg == NULL)
        return (84);
    if ((all_path = get_all_path(*envp, prog_name)) == NULL)
        return (84);
    exec_file = get_exec_path(all_path, prog_name);
    if (exec_file == NULL)
        return (84);
    exec_with_arg(exec_file, arguments, *envp);
    free_default_table(all_path, arguments);
    free(prog_name);
    free(exec_file);
    return (0);
}