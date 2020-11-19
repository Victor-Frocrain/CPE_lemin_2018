/*
** EPITECH PROJECT, 2019
** tests_parser.c
** File description:
** tests_parser.c
*/

#include "lemin.h"

Test(parser, is_int_minus_one)
{
    char *str = "-1";

    cr_assert(is_int(str));
}

Test(parser, is_int_plus_one)
{
    char *str = "+1";

    cr_assert(is_int(str));
}

Test(parser, is_int_not_int)
{
    char *str = "din";

    cr_assert(!is_int(str));
}
