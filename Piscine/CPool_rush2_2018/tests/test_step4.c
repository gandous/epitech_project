/*
** EPITECH PROJECT, 2018
** test step 4
** File description:
** test step 4
*/

#include <criterion/criterion.h>

char *search_language(char *text);

Test(search_lettera, return_letter_count)
{
    char *result = search_language("Je suis actuellement en train de finir mon rush pour avoir une bonne note");
    cr_assert_str_eq(result, "French");
}
