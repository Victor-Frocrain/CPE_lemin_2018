/*
** EPITECH PROJECT, 2019
** my_put_no_printable.c
** File description:
** Replace no printable char by a backslash
*/

#include "my_printf.h"

void print_tree_first_digit(char *str, int i)
{
    for (int j = 100; j >= 1; j /= 10) {
        if (str[i] / j == 0)
            my_putchar('0');
        else
            my_put_nbr(str[i] / j);
        str[i] %= j;
    }
}

void my_put_no_printable(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] >= '!' && str[i] <= '~')
            my_putchar(str[i]);
        else {
            my_putchar('\\');
            print_tree_first_digit(str, i);
        }
    }
}
