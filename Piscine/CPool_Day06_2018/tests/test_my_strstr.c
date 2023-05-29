/*
** EPITECH PROJECT, 2018
** test 
** File description:
** test file
*/

#include <criterion/criterion.h>

char *my_strstr(char *str, char const *to_find);

Test(my_revstr, return_value_is_find)
{
    char str[15] = "seHelltHellogt";
    char find[6] = "Hello";

    cr_assert_str_eq(my_strstr(str, find), "Hellogt");
}
