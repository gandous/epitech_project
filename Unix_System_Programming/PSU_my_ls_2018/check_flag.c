/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** check_flag
*/

#include <stdlib.h>

void check_line_flag(char *line, char *flag_k, int *nb_file)
{
    char flag[6] = "lRdrt";
    int ii;

    if (line[0] != '-') {
        *nb_file += 1;
        return;
    }
    for (int i = 1 ; line[i] != '\0' ; i += 1) {
        for (ii = 0 ; flag[ii] != line[i] && flag[ii] != '\0' ; ii += 1);
        if (flag[ii] != '\0')
            flag_k[ii] = line[i];
    }
}

char *check_flag(int argc, char **argv, int *nb_file)
{
    char *flag = NULL;

    if ((flag = malloc(sizeof(char) * 6)) == NULL)
        return (NULL);
    for (int i = 0 ; i < 6 ; i += 1) {
        flag[i] = '0';
    }
    flag[5] = '\0';
    for (int i = 1 ; i < argc ; i += 1) {
        check_line_flag(argv[i], flag, nb_file);
    }
    return (flag);
}