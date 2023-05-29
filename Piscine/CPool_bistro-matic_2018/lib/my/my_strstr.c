/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** none
*/

int my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int ii = 0;
    
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find[ii] && str[i + 1] != to_find[ii + 1])
            ii = 0;
        else if (str[i] == to_find[ii])
            ii++;
        if (str[i + 1] == to_find[ii] && to_find[ii + 1] == '\0')
            break;
    }
    i++;
    i -= ii;
    return(i);
}
