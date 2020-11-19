/*
** EPITECH PROJECT, 2019
** my_printf.h
** File description:
** my_printf.h
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include "my.h"

void my_printf(char *str, ...);
void conv_base(int nb, int base, char c);
void my_put_no_printable(char *str);
void my_put_unsigned_nbr(unsigned int nb);
void my_puterror(char *str);

#endif /* MY_PRINTF_H_ */
