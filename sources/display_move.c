/*
** EPITECH PROJECT, 2019
** display_move.c
** File description:
** display_move.c
*/

#include "lemin.h"

int way_len(chain_list_t *chain_list)
{
    int count = 0;

    for (list_t *list = chain_list->start; list->next && list->next[0];
    list = list->next[0], count++);
    return (count);
}

char *search_pos(ant_t *ant, int count)
{
    list_t *node = ant->chain_list->start;

    for (; count > 0; count--) {
        node = node->next[0];
    }
    return (node->id);
}

void display_results(ant_t *ant, int k, int i, int way_lenght)
{
    if (k > 0 && k <= way_lenght) {
        my_printf("P%d-%s", i, search_pos(ant, k));
        if (k > 1)
            my_putchar(' ');
    }
}

void display_move(ant_t *ant)
{
    int way_lenght = way_len(ant->chain_list);
    int j = 0;
    int i = 0;
    int k = 0;

    my_putstr("#moves");
    for (j = 1; j < ant->nb_ant + way_lenght + 1; j++) {
        for (i = 1; i <= ant->nb_ant; i++) {
            k = j - i;
            display_results(ant, k, i, way_lenght);
        }
        my_putchar('\n');
    }
}
