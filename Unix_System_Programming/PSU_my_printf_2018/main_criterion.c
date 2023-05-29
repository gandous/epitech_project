/*
** EPITECH PROJECT, 2018
** main criterion 
** File description:
** test file
*/

#include  <criterion/criterion.h>
#include  <criterion/redirect.h>
#include "my.h"

void  redirect_all_std(void)
{
    cr_redirect_stdout ();
    cr_redirect_stderr ();
}

Test(my_printf , simple_string , .init = redirect_all_std)
{
    my_printf("hello  world");
    cr_assert_stdout_eq_str("hello  world");
}

Test(my_printf , simple_nb_d , .init = redirect_all_std)
{
    my_printf("%d", 123);
    cr_assert_stdout_eq_str("123");
}

Test(my_printf , simple_bin_i , .init = redirect_all_std)
{
    my_printf("%i", -100);
    cr_assert_stdout_eq_str("-100");
}

Test(my_printf , simple_string_flag , .init = redirect_all_std)
{
    my_printf("%s", "hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf , complex_string_flag , .init = redirect_all_std)
{
    char temp[7] = "hello";
    temp[1] = 6;
    my_printf("%S", temp);
    cr_assert_stdout_eq_str("h\\006llo");
}

Test(my_printf , simple_char , .init = redirect_all_std)
{
    my_printf("%c", 'T');
    cr_assert_stdout_eq_str("T");
}

Test(my_printf , hexa_min , .init = redirect_all_std)
{
    my_printf("%x", 15347);
    cr_assert_stdout_eq_str("3bf3");
}

Test(my_printf , hexa_maj , .init = redirect_all_std)
{
    my_printf("%X", 326584);
    cr_assert_stdout_eq_str("4FBB8");
}

Test(my_printf , bin_simple , .init = redirect_all_std)
{
    my_printf("%b", 10);
    cr_assert_stdout_eq_str("1010");
}

Test(my_printf , bin , .init = redirect_all_std)
{
    my_printf("%b", 2350);
    cr_assert_stdout_eq_str("100100101110");
}

Test(my_printf , unsigned_int , .init = redirect_all_std)
{
    my_printf("%u", 3000000000);
    cr_assert_stdout_eq_str("3000000000");
}

Test(my_printf , base_octal, .init = redirect_all_std)
{
    my_printf("%o", 125);
    cr_assert_stdout_eq_str("175");
}

Test(my_printf , long_nb , .init = redirect_all_std)
{
    my_printf("%ld", 12236521458);
    cr_assert_stdout_eq_str("12236521458");
}

Test(my_printf , long_syntax_uncomplite , .init = redirect_all_std)
{
    my_printf("%l");
    cr_assert_stdout_eq_str("%l");
}

Test(my_printf , unreaconize_flag , .init = redirect_all_std)
{
    my_printf("hello%m");
    cr_assert_stdout_eq_str("hello%m");
}

Test(my_printf , multiple_flag , .init = redirect_all_std)
{
    my_printf("%d%s", 123, "hello");
    cr_assert_stdout_eq_str("123hello");
}

Test(my_printf , flag_p , .init = redirect_all_std)
{
    my_printf("%p", 121);
    cr_assert_stdout_eq_str("0x79");
}

Test(my_printf , flag_string_and_int , .init = redirect_all_std)
{
    my_printf("%s%dhello", "hello", 253);
    cr_assert_stdout_eq_str("hello253hello");
}

Test(my_printf , flag_string_and_int_1 , .init = redirect_all_std)
{
    my_printf("%dh%dello", 12, 253);
    cr_assert_stdout_eq_str("12h253ello");
}

Test(my_printf , flag_string_and_int_2 , .init = redirect_all_std)
{
    my_printf("%d%dhello", 12, 253);
    cr_assert_stdout_eq_str("12253hello");
}

Test(my_printf , flag_string_and_int_3 , .init = redirect_all_std)
{
    my_printf("%s%c world", "hell", 'o');
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf , flag_double_pourc , .init = redirect_all_std)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}


Test(my_printf , flag_long , .init = redirect_all_std)
{
    my_printf("%%%ld", 12345678998);
    cr_assert_stdout_eq_str("%12345678998");
}

Test(my_printf , flag_long_string , .init = redirect_all_std)
{
    my_printf("%%%ld% %s", 12345678998, "hello");
    cr_assert_stdout_eq_str("%12345678998% hello");
}

Test(my_printf , flag_mise_en_page , .init = redirect_all_std)
{
    my_printf("\t\t\n\t%d", 123456789);
    cr_assert_stdout_eq_str("\t\t\n\t123456789");
}

Test(my_printf , hard_flag , .init = redirect_all_std)
{
    my_printf("%.2d", 123);
    cr_assert_stdout_eq_str("%.2d");
}

Test(my_printf , hard_flag_2 , .init = redirect_all_std)
{
    my_printf("---%*d----\n", 123);
    cr_assert_stdout_eq_str("---%*d----\ns");
}