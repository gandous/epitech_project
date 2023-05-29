/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

char *get_next_line(int fd);

int main(int argc, char **argv)
{
    int fd = open("test_file", O_RDONLY);
    char *temp = get_next_line(fd);

    while (temp != NULL) {
        printf("%s\n", temp);
        temp = get_next_line(fd);
    }
    close(fd);
}
