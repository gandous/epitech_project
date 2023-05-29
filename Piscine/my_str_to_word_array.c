/*
** EPITECH PROJECT, 2018
** make an array
** File description:
** create an array with string
*/

#include <stdlib.h>

int is_alpha(char my_char) {
    if (my_char < '0' || (my_char > '9' && my_char < 'A')) {
        return (0);
    }
    if ((my_char > 'Z' && my_char < 'a') || my_char > 'z') {
        return (0);
    }
    return (1);
}

int number_of_word(char const *str)
{
    int size = 0;
    int index = 0;

    while (str[index] != '\0') {
        if (is_alpha(str[index]) == 0) {
            size++;
        }
        index++;
    }
    if (is_alpha(str[index-1]) == 1) {
        size++;
    }
    return (size);
}

int my_word_size(int start, char const *str)
{
    int word_size = start;

    while (is_alpha(str[word_size]) == 1 && str[word_size] != '\0') {
        word_size++;
    }
    return (word_size-start);
}

char **my_str_to_word_array(char const *str)
{
    char **dest;
    int size = number_of_word(str);
    int index = 0;
    int index2 = 0;
    int word_size = 0;

    dest = malloc(size + 1);
    while (index < size) {
        word_size = my_word_size(index2);
        dest[index] = malloc(word_size + 1);
        for (int i = 0 ; i < word_size ; i++) {
            dest[indx][i] = str[index2];
            index2++;
        }
        index++;
    }
    dest[index] = malloc[2];
    dest[index] = '\0';
    return (dest);
}
