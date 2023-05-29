/*
** EPITECH PROJECT, 2018
** load 2 day array in file
** File description:
** load_2d_array_from_file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

int number_size(int nb)
{
    int result = 1;

    while (nb > 9) {
        nb /= 10;
        result += 1;
    }
    return (result);
}

char **load_2d_array_from_file(char const *filepath, int nb_rows, int nb_cols)
{
    char **temp = NULL;
    int fd = open(filepath, O_RDONLY);
    char buff[nb_cols + 1];

    read(fd, buff, number_size(nb_rows) + 1);
    if (fd < 0)
        return (NULL);
    if (nb_rows == 1)
        nb_cols -= 1;
    temp = mem_alloc_2d_array(nb_rows, nb_cols);
    for (int i = 0 ; i < nb_rows ; i += 1) {
        read(fd, buff, nb_cols + 1);
        buff[nb_cols] = '\0';
        for (int ii = 0 ; ii < nb_cols ; ii += 1)
            temp[i][ii] = buff[ii];
        temp[i][nb_cols] = '\0';
    }
    close(fd);
    return (temp);
}