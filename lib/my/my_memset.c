/*
** EPITECH PROJECT, 2019
** my_memset.c
** File description:
** Setup the memory
*/

#include "my.h"

char *my_memset(char c, int nb)
{
    int i = 0;
    char *str;

    if (nb > 1000)
        return (NULL);
    str = malloc(sizeof(char) * (nb + 1));
    for (; i < nb; i++)
        str[i] = c;
    str[nb] = 0;
    return (str);
}
