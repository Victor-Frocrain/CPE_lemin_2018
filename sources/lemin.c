/*
** EPITECH PROJECT, 2019
** get_map.c
** File description:
** get_map.c
*/

#include "lemin.h"

int lemin(void)
{
    ant_t *ant = malloc(sizeof(ant_t));

    if (!ant)
        return (MY_ERROR);
    ant->tunnels = NULL;
    ant->chain_list = malloc(sizeof(chain_list_t));
    ant->chain_list->node_start = NULL;
    ant->chain_list->start = NULL;
    ant->chain_list->end = NULL;
    if (!ant->chain_list || get_nb_ant(ant) ||
    get_room(ant) || link_room(ant)) {
        display_graph(ant);
        return (MY_ERROR);
    } else
        display_graph(ant);
    if (!pathfinding(ant->chain_list->start, ant->chain_list->end->id, NULL))
        return (MY_ERROR);
    display_move(ant);
    return (MY_SUCCESS);
}
