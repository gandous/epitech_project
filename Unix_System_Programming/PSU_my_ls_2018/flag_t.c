/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** flag_t
*/

#include <stdlib.h>
#include "my_ls.h"

file_name_t *add_new_elem(char *name)
{
    file_name_t *temp = NULL;
    struct stat sb;

    temp = malloc(sizeof(file_name_t));
    if (temp == NULL)
        return (NULL);
    temp->file_name = my_strcpy(name);
    if (stat(name, &sb) == -1)
        return (NULL);
    temp->date = sb.st_mtime;
    return (temp);
}

file_name_t *recup_t_file(char *dir_path)
{
    DIR *directory = opendir(dir_path);
    struct dirent *content = NULL;
    file_name_t *temp = NULL;
    file_name_t *list = NULL;

    if (directory == NULL)
        return (NULL);
    content = readdir(directory);
    while (content != NULL) {
        if (content->d_name[0] != '.') {
            temp = add_new_elem(content->d_name);
            temp->next = list;
            list = temp;
        }
        content = readdir(directory);
    }
    closedir(directory);
    return (list);
}

time_t display_bigger(file_name_t *list, time_t prev, int *display)
{
    time_t max = 0;
    file_name_t *temp = list;

    while (temp != NULL) {
        if (temp->date > max && temp->date < prev)
            max = temp->date;
        temp = temp->next;
    }
    while (list != NULL) {
        if (list->date == max) {
            my_putstr(list->file_name);
            my_putchar('\n');
            *display += 1;
        }
        list = list->next;
    }
    return (max);
}

int calc_size(file_name_t *list)
{
    int size = 0;

    while (list != NULL) {
        size += 1;
        list = list->next;
    }
    return (size);
}

int make_t_flag(char *dir_path)
{
    file_name_t *list = NULL;
    int list_size = -1;
    int display = 0;
    time_t previous = 9999999999;
    file_name_t *temp = NULL;

    list = recup_t_file(dir_path);
    list_size = calc_size(list);
    while (list_size > display) {
        previous = display_bigger(list, previous, &display);
    }
    list_size = calc_size(list);
    while (list != NULL) {
        temp = list->next;
        free(list);
        list = temp->next;
    }
    return (0);
}