/*
** EPITECH PROJECT, 2019
** navy
** File description:
** Navy file pass in argument verification
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "navy.h"

static int is_valid_char1(char *str, int i)
{
    switch (i % 8) {
    case 0:
        if (str[i] < '2' || str[i] > '5')
            return (FALSE);
        break;
    case 1:
    case 4:
        if (str[i] != ':')
            return (FALSE);
        break;
    }
    return (TRUE);
}

static int is_valid_char2(char *str, int i)
{
    switch (i % 8) {
    case 2:
    case 5:
        if (is_char_alpha_navy(str[i]) == FALSE)
            return (FALSE);
        break;
    case 3:
    case 6:
        if (is_digit_navy(str[i]) == FALSE)
            return (FALSE);
        break;
    case 7:
        if (str[i] != '\n')
            return (FALSE);
        break;
    }
    return (TRUE);
}

static int is_valid_buffer(char *str)
{
    for (int i = 0 ; i < 31 ; i++) {
        if (is_valid_char1(str, i) == FALSE)
            return (FALSE);
        if (is_valid_char2(str, i) == FALSE)
            return (FALSE);
    }
    return (TRUE);
}

int is_navy_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[34];

    if (fd == -1)
        return (FALSE);
    if (read(fd, buffer, 33) != 32)
        return (FALSE);
    close(fd);
    if (is_valid_buffer(buffer) == FALSE)
        return (FALSE);
    return (TRUE);
}
