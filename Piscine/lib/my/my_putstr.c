/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** print a string
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str += 1;
    }
    return (0);
}
