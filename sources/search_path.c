/*
** EPITECH PROJECT, 2019
** search_path
** File description:
** search_path function
*/

#include "lemin.h"

bool is_already_seen(char **way, char *id)
{
    for (int i = 0; way[i]; i++)
        if (my_strcmp(way[i], id))
            return (true);
    return (false);
}

char **add_way(char **actual_way, char *pos)
{
    char **new_way = malloc(sizeof(char *) * (my_chartablen(actual_way) + 2));
    int i = 0;

    if (!new_way)
        return (NULL);
    for (; actual_way && actual_way[i]; i++)
        new_way[i] = actual_way[i];
    new_way[i++] = pos;
    new_way[i] = NULL;
    return (new_way);
}

int node_size(list_t **node)
{
    int i = 0;

    for (; node && node[i]; i++);
    return (i);
}

list_t **remove_link(list_t **node)
{
    int i = 0;
    int size = node_size(node) - 1;
    list_t **new_next = malloc(sizeof(list_t *) * (size + 1));

    if (!node)
        return (NULL);
    for (; i < size; i++)
        new_next[i] = node[i + 1];
    new_next[size] = NULL;
    free(node);
    return (new_next);
}

bool pathfinding(list_t *node, char *id_end, char **way)
{
    bool is_end = false;
    bool is_seen = false;

    for (int i = 0; !is_end && node->next && node->next[i]; is_seen = false) {
        if (my_strcmp(node->next[i]->id, id_end))
            return (true);
        if ((!way) || (way && !is_already_seen(way, node->next[i]->id)))
            is_end = pathfinding(node->next[i],
            id_end, add_way(way, node->next[i]->id));
        else
            is_seen = true;
        if (!is_end || is_seen)
            node->next = remove_link(node->next);
    }
    if (way)
        free(way);
    return (is_end);
}
