/*
** EPITECH PROJECT, 2018
** test my rev str
** File description:
** test rev str
*/

#include <criterion/criterion.h>

char *my_revstr(char *str);

Test(my_revstr, return_value_is_reversed)
{
    char str[6] = {0};

    strcpy(str, "Hello");
    cr_assert_str_eq(my_revstr(str), "olleH");
}
