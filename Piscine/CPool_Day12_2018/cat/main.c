/*
** EPITECH PROJECT, 2018
** cat
** File description:
** reprodiuce the cat fonction
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int main(int argc, char **argv){
    int fd;
    char buffer[30001];

    for (int i = 1 ; i < argc ; i++) {
        fd = open(argv[i], O_RDONLY);
        if (fd == -1) {
            write("Error with open\n", 15);
            return (84);
        }
        while (read(fd, buffer, 30000) != 0) {
            my_putstr(fd);
        }
        close(fd);
    }
}
