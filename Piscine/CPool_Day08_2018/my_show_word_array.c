/*
** EPITECH PROJECT, 2018
** print array
** File description:
** print an array of word
*/

int my_show_word_array(char * const * tab)
{
    for (int index = 0 ; tab[index] != '\0' ; index++) {
        my_putstr(tab[index]);
        my_putchar('\n');
    }
    return (0);
}
