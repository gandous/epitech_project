/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** array_remove
*/

#include <stdlib.h>
#include "minishell.h"

int verif_line(char **dest, char *src, char *to_rm)
{
    char *temp = NULL;

    if (compare_var(src, to_rm) == -1) {
        temp = generate_row(src);
        if (temp == NULL)
            return (84);
        *dest = temp;
        return (0);
    } else {
        return (-1);
    }
}

char **remove_from_array(char *str, char **array)
{
    char **temp = NULL;
    int size = count_size_array(array) - 1;
    int index = 0;
    int result = 0;

    temp = malloc(sizeof(char *) * (size + 1));
    if (temp == NULL)
        return (NULL);
    temp[size] = NULL;
    for (int i = 0 ; array[i] != NULL ; i += 1) {
        result = verif_line(&(temp[index]), array[i], str);
        if (result == 84)
            return (NULL);
        else if (result == 0)
            index += 1;
    }
    for (int i = 0 ; array[i] != NULL ; i += 1)
        free(array[i]);
    free(array);
    return (temp);
}

char **remove_at_index(char **array, int index_rm)
{
    char **temp = NULL;
    int size = count_size_array(array) - 1;
    int index = 0;
    int result = 0;

    temp = malloc(sizeof(char *) * (size + 1));
    if (temp == NULL)
        return (NULL);
    temp[size] = NULL;
    for (int i = 0 ; array[i] != NULL ; i += 1) {
        if (i != index_rm) {
            temp[index] = array[i];
            index += 1;
        }
    }
    free(array[index_rm]);
    free(array);
    return (temp);
}