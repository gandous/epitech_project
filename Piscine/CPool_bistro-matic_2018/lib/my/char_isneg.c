/*
** EPITECH PROJECT, 2018
** char is neg
** File description:
** return 1 if the char is neg
*/

int char_isneg(char *str)
{
    if (str[0] == '-') {
        return (1);
    }
    return (0);
}
