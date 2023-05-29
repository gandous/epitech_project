/*
** EPITECH PROJECT, 2018
** bonus
** File description:
** all function to load the map name
*/

#include "load_file.h"
#include "my_sokoban.h"

int my_line_width(char *str, int start)
{
    int i;

    for (i = start ; str[i] != '\0' && str[i] != '\n' ; i += 1);
    return (i - start);
}

void load_ligne_name(char *buff, char *dest, int *i)
{
    int ind;

    for (ind = 0 ; buff[*i] != '\n' && buff[*i] != '\0' ; *i += 1, ind += 1) {
        dest[ind] = buff[*i];
    }
    dest[ind] = '\0';
    if (buff[*i] != '\0')
        *i += 1;
}

void load_name(char **text, int fd, ssize_t size)
{
    char buff[size + 1];
    int line = 0;

    read(fd, buff, size);
    buff[size] = '\0';
    for (int i = 0 ; buff[i] != '\0' ; line += 1) {
        refresh();
        text[line] = malloc(sizeof(char) * (my_line_width(buff, i) + 1));
        load_ligne_name(buff, text[line], &i);
    }
    text[line] = NULL;
}

char **load_map_name(void)
{
    int fd;
    struct stat sb;
    char **temp = NULL;

    fd = open(FILE_NAME, O_RDONLY);
    if (fd == -1)
        exit (84);
    if (stat(FILE_NAME, &sb) == -1)
        exit (84);
    temp = malloc(sizeof(char *) * (sb.st_size ));
    if (temp == NULL)
        exit (84);
    load_name(temp, fd, sb.st_size);
    close(fd);
    return (temp);
}