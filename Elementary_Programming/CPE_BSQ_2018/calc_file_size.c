/*
** EPITECH PROJECT, 2018
** calc_file_size
** File description:
** calc the size of the first line and the height
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

int fisrt_line_isnumber(char *buff)
{
    int i;

    for (i = 0 ; buff[i] != '\n' && buff[i] != '\0' ; i++) {
        if (buff[i] < '0' || buff[i] > '9')
            return (0);
    }
    if ((i == 0 && buff[i] == '\0') || (i == 0 && buff[i] == '\n'))
        return (0);
    return (1);
}

file_size_t *calc_file_size(char const *filepath)
{
    struct stat sb;
    file_size_t *temp = NULL;
    int fd = open(filepath, O_RDONLY);
    char buff[201];

    if (stat(filepath, &sb) == -1)
        exit(84);
    temp = malloc(sizeof(file_size_t));
    if (temp == NULL || sb.st_size <= 2)
        exit(84);
    read(fd, buff, 200);
    if (fisrt_line_isnumber(buff) == 0)
        exit (84);
    temp->height = my_getnbr(buff);
    temp->width = (sb.st_size - number_size(temp->height)) / temp->height - 1;
    close(fd);
    return (temp);
}