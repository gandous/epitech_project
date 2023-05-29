/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** load files headers
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_sokoban.h"

#ifndef LOAD_FILE_H_
#define LOAD_FILE_H_

#define FILE_NAME "map_name"

typedef struct load_map {
    ssize_t read;
    ssize_t last_read;
    int i;
} load_map_t;

map_t *load_file(char *filepath);
int verif_map(map_t *data);
void my_strcpy(char *dest, char *src);

#endif
