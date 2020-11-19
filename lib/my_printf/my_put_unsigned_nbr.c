/*
** EPITECH PROJECT, 2019
** my_put_unsigned_nbr.c
** File description:
** Print the unsigned intergers
*/

#include "my_printf.h"

void my_put_unsigned_nbr(unsigned int nb)
{
    unsigned long mult = 1;
    int res;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    for (; nb / mult >= 10; mult *= 10);
    for (; mult > 0; mult /= 10) {
        res = nb / mult;
        my_putchar(res + '0');
        nb -= res * mult;
    }
}
