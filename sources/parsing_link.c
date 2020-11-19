/*
** EPITECH PROJECT, 2019
** parsing_link.c
** File description:
** parsing_link.c
*/

#include "lemin.h"

bool link_room(ant_t *ant)
{
    char *str = ant->first_link;

    for (int j = 0; str; str = manage_input(true, false, false)) {
        for (; str && str[j] && str[j] != '-'; j++);
        str[j] = 0;
        if (link_list(ant->chain_list, str, str + j + 1))
            return (true);
        ant->tunnels = add_tunnels(ant->tunnels, str, str + j + 1);
        if (!ant->tunnels)
            return (true);
    }
    return (false);
}
