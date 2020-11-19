/*
** EPITECH PROJECT, 2019
** my_printf.c
** File description:
** my_printf
*/

#include "my_printf.h"

void print_conv_base(char *str, va_list list, int i)
{
    if (str[i] == 'b')
        conv_base(va_arg(list, int), 2, '0');
    if (str[i] == 'x')
        conv_base(va_arg(list, int), 16, 'a');
    if (str[i] == 'X')
        conv_base(va_arg(list, int), 16, 'A');
    if (str[i] == 'o')
        conv_base(va_arg(list, int), 8, '0');
    if (str[i] == 'p')
        conv_base(va_arg(list, int), 16, '0');
}

void main_manage_mod(char *str, va_list list, int i)
{
    if (str[i] == 's')
        my_putstr(va_arg(list, char *));
    if (str[i] == 'S')
        my_put_no_printable(va_arg(list, char *));
    if (str[i] == 'c')
        my_putchar(va_arg(list, int));
    if (str[i] == 'd' || str[i] == 'i')
        my_put_nbr(va_arg(list, int));
    if (str[i] == 'u')
        my_put_unsigned_nbr(va_arg(list, unsigned int));
    if (str[i] == '%')
        my_putchar('%');
    if (str[i] == 'e')
        my_puterror(va_arg(list, char *));
    print_conv_base(str, list, i);
}

void my_printf(char *str, ...)
{
    va_list list;

    va_start(list, str);
    for (int i = 0; str[i]; i++) {
        if (str[i] == '%') {
            main_manage_mod(str, list, i + 1);
            i++;
        } else
            my_putchar(str[i]);
    }
    va_end(list);
}
