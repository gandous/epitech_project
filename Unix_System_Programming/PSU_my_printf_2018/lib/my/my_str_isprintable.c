/*
** EPITECH PROJECT, 2018
** my str is printable
** File description:
** my str is printable
*/

int my_str_isprintable(char const str)
{
    if (str < 32 || str >= 127) {
        return (-1);
    } else {
        return (0);
    }
}
