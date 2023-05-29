/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** generate_adv_map
*/

#include <stdlib.h>

/*
Generate adv map
return NULL if failed
*/
char **generate_adv_map(void)
{
    char **temp = NULL;

    if ((temp = malloc(sizeof(char*) * 9)) == NULL)
        return (NULL);
    temp[8] = NULL;
    for (int i = 0 ; i < 8 ; i += 1) {
        if ((temp[i] = malloc(sizeof(char) * 9)) == NULL)
            return (NULL);
        for (int ind = 0 ; ind < 8 ; ind += 1)
            temp[i][ind] = '.';
        temp[i][8] = '\0';
    }
    return (temp);
}