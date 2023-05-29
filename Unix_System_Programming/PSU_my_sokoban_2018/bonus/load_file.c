/*
** EPITECH PROJECT, 2018
** load file
** File description:
** load file
*/

#include "my_sokoban.h"
#include "load_file.h"

int load_ligne(char **save, char **map, char *line, load_map_t data)
{
    ssize_t read = data.read;
    int index = data.i;

    save[index] = malloc(sizeof(char) * (read + 1));
    map[index] = malloc(sizeof(char) * (read + 1));
    if (save[index] == NULL || map[index] == NULL)
        return (ERROR);
    my_strcpy(save[index], line);
    my_strcpy(map[index], line);
    return (SUCCES);
}

void load_in_array(char **save, char **map, char *filepath)
{
    FILE * fp;
    char *line = NULL;
    load_map_t data;
    size_t len = 0;

    data.last_read = 0;
    fp = fopen(filepath, "r");
    if (fp == NULL)
        exit(84);
    data.i = 0;
    while ((data.read = getline(&line, &len, fp)) != -1) {
        if (load_ligne(save, map, line, data) == ERROR)
            return;
        data.i += 1;
        data.last_read = data.read;
    }
    save[data.i] = '\0';
    map[data.i] = '\0';
    free(line);
    fclose(fp);
}

void search_player(point_t *pos, char **map)
{
    int ii = 0;

    for (int i = 0 ; map[i] != NULL ; i++) {
        for (ii = 0 ; map[i][ii] != '\0' && map[i][ii] != 'P' ; ii += 1);
        if (map[i][ii] == 'P') {
            pos->x = ii;
            pos->y = i;
            return;
        }
    }
}

int file_height(char *filepath)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    int size = 0;

    fp = fopen(filepath, "r");
    if (fp == NULL)
        exit(84);
    for (size = 0 ; getline(&line, &len, fp) != -1 ; size += 1);
    free(line);
    fclose(fp);
    return (size);
}

map_t *load_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    map_t *temp = NULL;
    int size = file_height(filepath);

    temp = malloc(sizeof(map_t));
    if (temp == NULL)
        exit(84);
    temp->save = malloc(sizeof(char *) *(size + 1));
    temp->map = malloc(sizeof(char *) * (size + 1));
    temp->pos = malloc(sizeof(point_t *));
    temp->w = 0;
    if (temp->save == NULL || temp->map == NULL || temp->pos == NULL)
        exit (84);
    load_in_array(temp->save, temp->map, filepath);
    if (verif_map(temp) == ERROR)
        exit (84);
    search_player(temp->pos, temp->map);
    return (temp);
}