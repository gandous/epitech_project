/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** 
*/

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str += 1;
    }
    return (0);
}
