/*
** EPITECH PROJECT, 2018
** make an array
** File description:
** create an array with string
*/

#include <stdlib.h>

int move_next_word(int index, char const *str);

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
    int index = move_next_word(index, str);

    while (str[index] != '\0') {
        if (is_alpha(str[index]) == 0) {
            size++;
            index = move_next_word(index, str);
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

int move_next_word(int index, char const *str)
{    
    while (is_alpha(str[index]) == 0 && str[index] != '\0') {
        index++;
    }
    return (index);
}

char **my_str_to_word_array(char const *str)
{
    char **dest;
    int number_word = number_of_word(str);
    int index = 0;
    int index2 = move_next_word(0, str);
    int word_size = 0;

    dest = malloc(sizeof(char*) * (number_word + 1));
    while (index < number_word) {
        word_size = my_word_size(index2, str);
        dest[index] = malloc(word_size + 1);
        for (int i = 0 ; i < word_size ; i++) {
            dest[index][i] = str[index2];
            index2++;
        }
        index2 = move_next_word(index2, str);
        index++;
    }
    dest[index] = malloc(2);
    dest[index] = '\0';
    return (dest);
}
