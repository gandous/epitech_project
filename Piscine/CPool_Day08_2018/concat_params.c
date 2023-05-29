/*
** EPITECH PROJECT, 2018
** concat param
** File description:
** return the argument into one string
*/

#include <stdlib.h>

int total_size(int argc,char **argv)
{
    int size = 0;

    for (int index = 0 ; index < argc ; index++) {
        size = size +  my_strlen(argv[index]);
    }
    return (size);
}

char *concat_params(int argc, char **argv)
{
    int size = total_size(argc, argv) + argc;
    char *dest;
    int dest_index = 0;

    dest = malloc(size + 1);
    if (dest == NULL) {
        return (NULL);
    }
    for (int index = 0 ; index < argc ; index++) {
        for (int index2 = 0 ; argv[index][index2] != '\0' ; index2++) {
            dest[dest_index] = argv[index][index2];
            dest_index++;
        }
        dest[dest_index] = '\n';
        dest_index++;
    }
    return (dest);
}
