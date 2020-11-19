/*
** EPITECH PROJECT, 2019
** tests_my_realloc.c
** File description:
** tests_my_realloc.c
*/

#include "lemin.h"

Test(my_realloc, intlen, .init = redirect_all_std)
{
    int *tab = malloc(sizeof(int) * 3);

    tab[0] = 1;
    tab[1] = 1;
    tab[2] = 1;
    cr_assert_eq(my_intlen(tab), 3);
}

Test(my_realloc, inttab, .init = redirect_all_std)
{
    int **tab = malloc(sizeof(int *) * 4);

    for (int i = 0; i < 3; i++) {
        tab[i] = malloc(sizeof(int) * 2);
        tab[i][0] = 1;
        tab[i][1] = 1;
    }
    tab[3] = NULL;
    cr_assert_eq(my_inttab(tab), 3);
}

Test(my_realloc, intalloc, .init = redirect_all_std)
{
    int *tab = malloc(sizeof(int) * 2);

    tab[0] = 1;
    tab[1] = 1;
    tab = my_intalloc(tab, 3);
    if (tab && tab[2])
        cr_assert_eq(tab[2], 3);
    else
        cr_assert(false);
}
