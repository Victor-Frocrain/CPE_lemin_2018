/*
** EPITECH PROJECT, 2019
** chain_list.c
** File description:
** chain_list.c
*/

#include "lemin.h"

void add_node(chain_list_t *chain_list, list_t *list)
{
    list_t *list2 = chain_list->node_start;

    if (!chain_list->node_start)
        chain_list->node_start = list;
    else {
        for (; list2 && list2->node_next; list2 = list2->node_next);
        list2->node_next = list;
    }
    list->next = NULL;
    list->node_next = NULL;
}

int fill_node(chain_list_t *chain_list, char *str)
{
    list_t *list = malloc(sizeof(list_t));
    int i = 0;
    char *new_str = my_strcpy(str);

    if (!new_str || !list || !is_node(new_str, chain_list))
        return (MY_ERROR);
    list->id = new_str;
    list->nb_link = 0;
    for (; new_str[i]; i++);
    list->x = my_getnbr(new_str + i + 1);
    i++;
    for (; new_str[i]; i++);
    list->y = my_getnbr(new_str + i + 1);
    add_node(chain_list, list);
    return (MY_SUCCESS);
}

int fill_first_node(chain_list_t *chain_list)
{
    char *str = manage_input(false, true, false);
    list_t *list = malloc(sizeof(list_t));
    int i = 0;

    if (!str || !list || !is_node(str, chain_list))
        return (MY_ERROR);
    list->id = str;
    list->nb_link = 0;
    for (; str[i]; i++);
    list->x = my_getnbr(str + i + 1);
    for (i++; str[i]; i++);
    list->y = my_getnbr(str + i + 1);
    add_node(chain_list, list);
    chain_list->start = list;
    return (MY_SUCCESS);
}

int fill_last_node(chain_list_t *chain_list)
{
    char *str = manage_input(false, false, true);
    list_t *list = malloc(sizeof(list_t));
    int i = 0;

    if (!str || !list || !is_node(str, chain_list))
        return (MY_ERROR);
    list->id = str;
    list->nb_link = 0;
    for (; str[i]; i++);
    list->x = my_getnbr(str + i + 1);
    for (i++; str[i]; i++);
    list->y = my_getnbr(str + i + 1);
    add_node(chain_list, list);
    chain_list->end = list;
    return (MY_SUCCESS);
}
