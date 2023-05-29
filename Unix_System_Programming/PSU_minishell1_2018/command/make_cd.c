/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** make_cd
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

int change_to_directory(char *dir, char ***envp)
{
    char *temp = NULL;

    if (str_compare("-", dir) == 0) {
        free(dir);
        dir = get_env("OLDPWD", *envp);
        if (dir == NULL)
            dir = "";
    }
    if (chdir(dir) == -1) {
        my_putstr(dir);
        my_putstr(": Permission denied.\n");
        return (84);
    }
    temp = get_env("PWD", *envp);
    replace_env("OLDPWD", temp, *envp);
    free(temp);
    temp = NULL;
    temp = getcwd(temp, 0);
    replace_env("PWD", temp, *envp);
    return (0);
}

int verif_perm_folder(char *filepath)
{
    struct stat sb;

    if (stat(filepath, &sb) == -1 && str_compare("-", filepath) == -1) {
        my_putstr(filepath);
        my_putstr(": No such file or directory.\n"); 
        return (-1);
    }
    return (0);
    
}

int make_cd(char *arg, char ***envp)
{
    char **arguments = my_str_to_word_array(arg);
    int size = 0;
    char *path = NULL;

    if (arguments == NULL)
        return (84);
    size = count_size_array(arguments);
    if (size == 1) {
        path = get_env("HOME", *envp);
        change_to_directory(path, envp);
        free(path);
    } else if (size == 2) {
        if (verif_perm_folder(arguments[1]) == 0)
            change_to_directory(arguments[1], envp);
    } else {
        my_putstr("cd: Too many arguments.\n");
    }
    return (0);
}