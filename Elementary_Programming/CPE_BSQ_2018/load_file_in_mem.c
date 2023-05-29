/*
** EPITECH PROJECT, 2018
** load file in memory
** File description:
** load a file and return it in a char *
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *mem_alloc(char const *, char const *);

char *load_file_in_mem(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buff[201];
    int size = 0;
    char *temp = NULL;

    if (fd < 0)
        return (NULL);
    size = read(fd, buff, 200);
    while (size > 0) {
        buff[size] = '\0';
        temp = mem_alloc(temp, buff);
        size = read(fd, buff, 200);
    }
    return (temp);
}