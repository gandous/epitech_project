/*
** EPITECH PROJECT, 2018
** str capitalize
** File description:
** str capitalize
*/

int is_lower(char str)
{
    if (str > 'a' && str < 'z') {
        return (1);
    }
    return (0);
}

char *my_strcapitalize(char *str)
{
    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] == ' ' && is_lower(str[i+1]) == 1) {
            str[i + 1] = str[i + 1] - 32;
        }
    }
    return (str);
}
