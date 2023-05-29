/*
** EPITECH PROJECT, 2018
** test step 2
** File description:
** test step 2
*/

#include <criterion/criterion.h>

int more_letter(int argc, char **argv);

Test(search_lettera, return_letter_count)
{
    char *text[] = {"./rush2", "bonjour", "o"};
    cr_assert_str_eq(more_letter(5, text), "o:2");
}
