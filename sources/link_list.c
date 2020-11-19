/*
** EPITECH PROJECT, 2019
** link_list.c
** File description:
** link_list.c
*/

#include "lemin.h"

bool redefined_list(list_t *list, int size, list_t *next_list)
{
    list_t **new_next_list = malloc(sizeof(list_t *) * (size + 2));
    int i = 0;

    if (!new_next_list)
        return (true);
    for (; i < size; i++)
        new_next_list[i] = list->next[i];
    free(list->next);
    new_next_list[size] = next_list;
    new_next_list[size + 1] = NULL;
    list->next = new_next_list;
    return (false);
}

bool add_next(list_t *list, list_t *list2)
{
    int count = 0;

    for (; count < list->nb_link; count++)
        if (my_strcmp(list->next[count]->id, list2->id)) {
            my_puterror("Error: the two rooms are already linked\n");
            return (true);
        }
    return (redefined_list(list, count, list2));
}

bool is_list_next(list_t *list, list_t *list2)
{
    if (list->nb_link == 0) {
        list->next = malloc(sizeof(list_t *) * 2);
        if (!list->next)
            return (true);
        list->next[0] = list2;
        list->next[1] = NULL;
    } else if (add_next(list, list2))
        return (true);
    list->nb_link++;
    return (false);
}

list_t *find_id_in_chain_list(chain_list_t *chain_list, char *id)
{
    for (list_t *list = chain_list->node_start; list; list = list->node_next)
        if (my_strcmp(list->id, id))
            return (list);
    my_puterror("Error: didn't found the id: ");
    my_puterror(id);
    my_puterror("\n");
    return (NULL);
}

bool link_list(chain_list_t *chain_list, char *id, char *id2)
{
    list_t *list;
    list_t *list2;

    if (my_strcmp(id, id2)) {
        my_puterror("Error: you can't link a room to herself\n");
        return (true);
    }
    list = find_id_in_chain_list(chain_list, id);
    list2 = find_id_in_chain_list(chain_list, id2);
    if (!list || !list2)
        return (MY_ERROR);
    if (!((chain_list->start && my_strcmp(id2, chain_list->start->id)) ||
        (chain_list->end && my_strcmp(id, chain_list->end->id))))
        if (is_list_next(list, list2))
            return (true);
    if (!((chain_list->start && my_strcmp(id, chain_list->start->id)) ||
        (chain_list->end && my_strcmp(id2, chain_list->end->id))))
        if (is_list_next(list2, list))
            return (true);
    return (false);
}
