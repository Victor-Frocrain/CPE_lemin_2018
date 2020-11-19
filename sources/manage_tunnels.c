/*
** EPITECH PROJECT, 2019
** manage_tunnels.c
** File description:
** manage_tunnels.c
*/

#include "lemin.h"

char **realloc_tunnels(char **tunnels, char *id, char *id2)
{
    char **new_tunnels = malloc(sizeof(char *) * (my_chartablen(tunnels) + 3));
    int i = 0;

    if (!new_tunnels)
        return (NULL);
    for (; new_tunnels && tunnels[i]; i++)
        new_tunnels[i] = tunnels[i];
    new_tunnels[i++] = id;
    new_tunnels[i++] = id2;
    new_tunnels[i] = NULL;
    free(tunnels);
    return (new_tunnels);
}

char **add_tunnels(char **tunnels, char *id, char *id2)
{
    if (!tunnels) {
        tunnels = malloc(sizeof(char *) * 3);
        if (!tunnels)
            return (NULL);
        tunnels[0] = id;
        tunnels[1] = id2;
        tunnels[2] = NULL;
    } else
        tunnels = realloc_tunnels(tunnels, id, id2);
    if (!tunnels)
        return (NULL);
    return (tunnels);
}
