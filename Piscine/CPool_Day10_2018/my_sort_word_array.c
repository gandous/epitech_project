/*
** EPITECH PROJECT, 2018
** sort array
** File description:
** sort array
*/

#include "include/my.h"
#include <stdlib.h>

int taille_tableau(char **tab)
{
    int index = 0;

    while (tab[index] != '\0') {
        index++;
    }
    return (index);
}

int my_sort_word_array(char **tab) {
    char **temp;
    int index = 0;
    int size = taille_tableau(tab);
    char *temp_word;

    temp = malloc((sizeof(char *) * size) + 1);
    for (int i = 0 ; i < 128 ; i++) {
        for (int index2 = 0 ; index2 < size ; index2++) {
            if (tab[index2][0] == i) {
                temp_word = malloc(sizeof(char) * my_strlen(tab[index2]) + 1);
                my_strcpy(temp_word, tab[index2]);
                tab[index2] = malloc(sizeof(char) * my_strlen(tab[index]) + 1);
                my_strcpy(tab[index2], tab[index]);
                tab[index] = malloc(sizeof(char) * my_strlen(temp_word) + 1);
                my_strcpy(tab[index], temp_word);
                free(temp_word);
                index++;
            }
            my_putchar(tab[index2][0]);
        }
        my_put_nbr(i);
    }
    my_show_word_array(temp);
    free(temp);
    return (0);
}

int main() {
    char *test_word[] = {"bonjour", "aa", "zzz", "lkj", "gfdfg", "fdsdf", 0};
    my_sort_word_array(test_word);
    my_show_word_array(test_word);
}
