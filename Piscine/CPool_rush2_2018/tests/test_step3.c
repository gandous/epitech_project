/*
** EPITECH PROJECT, 2018
** test step 3
** File description:
** test step 3
*/

#include <criterion/criterion.h>

int display_pour(int nb_lettre, int size);

Test(search_lettera, return_letter_count)
{
    cr_assert_eq(display_pour(2, 3), 333);
}
