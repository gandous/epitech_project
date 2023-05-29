/*
** EPITECH PROJECT, 2018
** find string
** File description:
** find the second in the first one
*/

char *my_strstr(char *str, char const *to_find)
{
    int index = 0;
    int index2 = 0;
    char *point;

    while (str[index] != '\0') {
        if (to_find[index2] == '\0') {
            break;
        } else if (str[index] == to_find[index2]) {
            index2++;
        } else {
            index2 = 0;
        }
        index++;
    }
    if (to_find[index2] == '\0') {
        point = &str[index - index2];
    } else {
        point = &str[index];
    }
    return (point);
}
