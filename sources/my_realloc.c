/*
** EPITECH PROJECT, 2019
** my_realloc
** File description:
** my_realloc function
*/

#include "lemin.h"

int my_chartablen(char **map)
{
    int count = 0;

    for (; map && map[count]; count++);
    return (count);
}

int my_intlen(int *tab)
{
    int i = 0;

    for (; tab && tab[i]; i++);
    return (i);
}

int my_inttab(int **tab)
{
    int i = 0;

    for (; tab && tab[i]; i++);
    return (i);
}

int *my_intalloc(int *tab, int pos)
{
    int i = 0;
    int len = my_intlen(tab);
    int *n_tab = malloc(sizeof(int) * (len + 1));

    for (; n_tab && len >= i; i++) {
        if (i == len)
            n_tab[i] = pos;
        else
            n_tab[i] = tab[i];
    }
    return (n_tab);
}
