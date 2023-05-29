/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** load_map
*/

#include <stdio.h>
#include <stdlib.h>
#include "runner.h"
#include "data_name.h"

int load_file_size(char *filepath, int *max_width)
{
    FILE *file = fopen(filepath, "r");
    char *line = NULL;
    size_t len = 0;
    int size = 0;
    int width = 0;

    if (file == NULL)
        return (-1);
    for (size = 0 ; (width = getline(&line, &len, file)) != -1 ; size += 1) {
        if (width > *max_width && line[width - 1] != '\n')
            *max_width = width;
        else if (width > *max_width && line[width - 1] == '\n')
            *max_width = width - 1;
    }
    fclose(file);
    free(line);
    return (size);
}

void my_strcpy_line(char *dest, char *src, int *i)
{
    for ( ; src[*i] != '\0' && src[*i] != '\n' ; *i += 1)
        dest[*i] = src[*i];
}

int load_line(char **temp, char *filepath, int width)
{
    FILE *file = fopen(filepath, "r");
    char *line = NULL;
    size_t len = 0;
    int size = 0;
    int ii = 0;

    for (int i = 0 ; getline(&line, &len, file) != -1 ; i += 1) {
        temp[i] = malloc(sizeof(char) * (width + 1));
        if (temp[i] == NULL) {
            temp[i] = NULL;
            return (-1);
        }
        ii = 0;
        my_strcpy_line(temp[i], line, &ii);
        for ( ; ii < width ; ii += 1)
            temp[i][ii] = ' ';
        temp[i][ii] = '\0';
    }
    fclose(file);
    free(line);
    return (0);
}

void free_map_data(map_data_t *data_map)
{
    char **str = data_map->map;

    for (int i = 0 ; str[i] != NULL ; i += 1)
        free(str[i]);
    free(str);
    free(data_map);
}

map_data_t *load_map(char *filepath)
{
    char **temp = NULL;
    int width = 0;
    int size = load_file_size(filepath, &width);
    map_data_t *data = NULL;

    if (size < 0)
        return (NULL);
    temp = malloc(sizeof(char *) * (size + 1));
    data = malloc(sizeof(map_data_t));
    if (load_line(temp, filepath, width) == -1) {
        for (int i = 0 ; temp[i] != NULL ; i += 1)
            free(temp[i]);
        free(data);
        return (NULL);
    }
    temp[size] = NULL;
    data->map = temp;
    data->height = size;
    data->width = width;
    data->index = 0;
    return (data);
}
