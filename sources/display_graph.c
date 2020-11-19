/*
** EPITECH PROJECT, 2019
** display_grap.c
** File description:
** display_graph.c
*/

#include "lemin.h"

bool display_room(chain_list_t *chain_list)
{
    bool ret = true;

    my_putstr("#rooms\n");
    if (chain_list && !chain_list->start) {
        my_putstr("##start\n");
        ret = false;
        my_puterror("Error: Missing the starting room\n");
    }
    if (chain_list && !chain_list->end) {
        my_putstr("##end\n");
        ret = false;
        my_puterror("Error: Missing the ending room\n");
    }
    for (list_t *list = chain_list->node_start; list; list = list->node_next) {
        if (chain_list->start && my_strcmp(list->id, chain_list->start->id))
            my_putstr("##start\n");
        if (chain_list->end && my_strcmp(list->id, chain_list->end->id))
            my_putstr("##end\n");
        my_printf("%s %d %d\n", list->id, list->x, list->y);
    }
    return (ret);
}

bool display_tunnels(char **tunnels, bool ret)
{
    bool link = false;

    my_putstr("#tunnels\n");
    for (int i = 0; tunnels && tunnels[i]; i += 2) {
        link = true;
        my_printf("%s-%s\n", tunnels[i], tunnels[i + 1]);
    }
    if (!link)
        my_puterror("Error: Missing tunnels\n");
    if (!ret)
        return (ret);
    return (link);
}

int display_graph(ant_t *ant)
{
    bool ret;

    if (ant->nb_ant > 0)
        my_printf("#number_of_ants\n%d\n", ant->nb_ant);
    else
        my_printf("#number_of_ants\n");
    ret = display_room(ant->chain_list);
    ret = display_tunnels(ant->tunnels, ret);
    if (!ret)
        return (MY_ERROR);
    return (MY_SUCCESS);
}
