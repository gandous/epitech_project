/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_strcpy
*/

void my_strcpy(const char *src, char *dest)
{
    for (int i = 0 ; src[i] != '\0' ; i += 1)
        dest[i] = src[i];
}

int my_strlen(const char *str)
{
    int len = 0;

    for ( ; str[len] != '\0' ; len += 1);
    return (len);
}