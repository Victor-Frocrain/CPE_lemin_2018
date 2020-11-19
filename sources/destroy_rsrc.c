/*
** EPITECH PROJECT, 2019
** destroy_ress.c
** File description:
** destory_ress.c
*/

#include "lemin.h"

void destroy_node(list_t *list)
{
    if (list->next)
        free(list->next);
    free(list->id);
    free(list);
}

void destroy_ress(ant_t *ant)
{
    list_t *list = ant->chain_list->node_start;

    for (list_t *list2 = ant->chain_list->node_start->node_next; list2;
        list = list2, list2 = list2->node_next)
        destroy_node(list);
    free(ant->chain_list);
    free(ant->tunnels);
}
