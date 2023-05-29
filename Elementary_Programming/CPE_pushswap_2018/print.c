/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** print
*/

#include <stdlib.h>
#include <unistd.h>
#include "pushswap.h"

void my_putstr(char *str, int size)
{
    write(1, str, size);
}

print_t *create_print_buff(void)
{
    print_t *buff = NULL;

    buff = malloc(sizeof(print_t));
    if (buff == NULL)
        return (NULL);
    buff->buff = malloc(sizeof(char) * PRINT_BUFFER);
    if (buff->buff == NULL)
        return (NULL);
    for (int i = 0 ; i < PRINT_BUFFER ; i += 1)
        buff->buff[i] = '\0';
    buff->index = 0;
    return (buff);
}

int my_strlen(char *str)
{
    int size = 0;

    for (size = 0 ; str[size] != '\0' ; size += 1);
    return (size);
}

void add_to_buff(print_t *print_data, char *str)
{
    int size = my_strlen(str);

    if (print_data->index + size >= PRINT_BUFFER) {
        print_data->buff[print_data->index] = '\0';
        my_putstr(print_data->buff, print_data->index);
        print_data->index = 0;
    }
    for (int i = 0 ; str[i] != '\0' ; i += 1, print_data->index += 1)
        print_data->buff[print_data->index] = str[i];
}

void display_buffer(print_t *print_data)
{
    print_data->buff[print_data->index-1] = '\n';
    print_data->buff[print_data->index] = '\0';
    my_putstr(print_data->buff, print_data->index);
}