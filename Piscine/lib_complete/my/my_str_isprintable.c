/*
** EPITECH PROJECT, 2018
** my str is printable
** File description:
** my str is printable
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (i < 20 || i > 126) {
            return (1);
        }
    }
    return (1);
}
