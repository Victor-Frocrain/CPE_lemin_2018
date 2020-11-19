/*
** EPITECH PROJECT, 2019
** tests_manage_input.c
** File description:
** tests_manage_input.c
*/

#include "lemin.h"

Test(manage_input, remove_space, .init = redirect_all_std)
{
    char *str = malloc(sizeof(char) * 6);

    str[0] = '1';
    str[1] = '2';
    str[2] = ' ';
    str[3] = ' ';
    str[4] = '3';
    str[5] = 0;
    str = remove_space(str, 2);
    cr_assert_str_eq(str, "12 3");
    free(str);
}

Test(manage_input, useless_char, .init = redirect_all_std)
{
    char *str = malloc(sizeof(char) * 6);

    str[0] = '1';
    str[1] = '2';
    str[2] = ' ';
    str[3] = ' ';
    str[4] = '3';
    str[5] = 0;
    cr_assert(is_useless_char(str, 2));
    free(str);
}

Test(manage_input, useless_char_at_end, .init = redirect_all_std)
{
    char *str = malloc(sizeof(char) * 6);

    str[0] = '1';
    str[1] = ' ';
    str[2] = '3';
    str[3] = '2';
    str[4] = ' ';
    str[5] = 0;
    cr_assert(is_useless_char(str, 4));
    free(str);
}

Test(manage_input, not_useless_char, .init = redirect_all_std)
{
    char *str = malloc(sizeof(char) * 6);

    str[0] = '1';
    str[1] = '2';
    str[2] = ' ';
    str[3] = ' ';
    str[4] = '3';
    str[5] = 0;
    cr_assert(!is_useless_char(str, 1));
    free(str);
}
