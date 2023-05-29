/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** make_ls
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_ls.h"

int flag_gestion(char *flag, struct dirent *cont, dir_name_t **dir, char *d)
{
    dir_name_t *temp;

    if (flag[0] == 'l') {
        make_l_flag(cont, d);
    } else {
        if (cont->d_name[0] != '.') {
            my_putstr(cont->d_name);
            my_putstr("\n");
        }
    }
    if (cont->d_type == 4 && cont->d_name[0] != '.' && flag[1] == 'R') {
        if ((temp = malloc(sizeof(dir_name_t))) == NULL)
            return (84);
        temp->name = my_strcpy(cont->d_name);
        temp->next = *dir;
        *dir = temp;
    }
}

int empty_save(dir_name_t *other_dir, char *dir_path, char *flag)
{
    while (other_dir != NULL) {
        my_putchar('\n');
        char *temp = create_dirpath(dir_path ,other_dir->name);
        make_ls(temp, flag, 1);
        other_dir = other_dir->next;
    }
}

void display_dir_path(char *flag, int print_n, char *dir_path)
{
    if (print_n == 1 || flag[1] == 'R') {
        my_putstr(dir_path);
        my_putstr(":\n");
    }
}

int make_ls(char *dir_path, char *flag, int print_n)
{
    DIR *directory = opendir(dir_path);
    struct dirent *content = NULL;
    dir_name_t *other_dir = NULL;

    if (directory == NULL)
        return (84);
    display_dir_path(flag, print_n, dir_path);
    if (flag[4] == 't') {
        closedir(directory);
        return (make_t_flag(dir_path));
    }
    if (flag[0] == 'l')
        print_total_size(dir_path);
    content = readdir(directory);
    while (content != NULL) {
        flag_gestion(flag, content, &other_dir, dir_path);
        content = readdir(directory);
    }
    closedir(directory);
    empty_save(other_dir, dir_path, flag);
    return  (0);
}