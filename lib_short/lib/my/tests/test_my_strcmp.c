/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(my_strcmp, test_strcmp)
{
    int v = my_strcmp("123", "123");

    cr_assert_eq(v, 0);
}

Test(my_strcmp, test_strcmp_2)
{
    int v = my_strcmp("123", "133");

    cr_assert_eq(v, -1);
}

Test(my_strcmp, test_strcmp_3)
{
    int v = my_strcmp("123", "12");

    cr_assert_eq(v, 51);
}