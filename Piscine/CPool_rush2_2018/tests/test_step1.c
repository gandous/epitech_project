/*
** EPITECH PROJECT, 2018
** test step 1
** File description:
** test step 1
*/

#include <criterion/criterion.h>

int search_letter(char *text, char letter);

Test(search_lettera, return_letter_count)
{
    cr_assert_eq(search_letter("Just because I don’t care doesn’t mean I 
don’t understand!", 'a'), 4);
}
