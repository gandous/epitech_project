/*
** EPITECH PROJECT, 2018
** str len
** File description:
** count size
*/

int str_len(char *str)
{
    int size = 0;
    int index = 0;

    while (str[index] == '0' || str[index] == '-') {
        index++;
    }
    while (str[index] != '\0') {
        index += 1;
        size += 1;
    }
    return (size);
}
