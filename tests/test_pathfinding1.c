/*
** EPITECH PROJECT, 2019
** test_pathfinding1
** File description:
** test_pathfinding1 function
*/

#include "lemin.h"

Test(search_path, is_already_seen_true, .init = redirect_all_std)
{
    char **way = malloc(sizeof(char *) * 5);

    way[0] = "a";
    way[1] = "b";
    way[2] = "c";
    way[3] = "d";
    way[4] = NULL;
    cr_assert(is_already_seen(way, "d"));
}

Test(search_path, is_already_seen_false, .init = redirect_all_std)
{
    char **way = malloc(sizeof(char *) * 4);

    way[0] = "a";
    way[1] = "b";
    way[2] = "c";
    way[3] = NULL;
    cr_assert(!is_already_seen(way, "d"));
}

Test(search_path, add_way, .init = redirect_all_std)
{
    char **way = malloc(sizeof(char *) * 2);

    way[0] = "a";
    way[1] = NULL;
    way = add_way(way, "b");
    cr_assert_eq(way[1], "b");
}

Test(search_path, node_size, .init = redirect_all_std)
{
    chain_list_t *chain_list = malloc(sizeof(chain_list_t));
    list_t *node = malloc(sizeof(list_t));
    list_t *node2 = malloc(sizeof(list_t));
    int nb = 0;
    int i = 0;

    chain_list->node_start = node;
    node->next = malloc(sizeof(list_t *) * 5);
    for (i = 0; i < 5; i++) {
        node->next[i] = node2;
    }
    node->next[i] = NULL;
    cr_assert_eq(node_size(node->next), 5);
    free(node->next);
    free(node);
    free(node2);
    free(chain_list);
}

Test(search_path, remove_link, .init = redirect_all_std)
{
    list_t *node = malloc(sizeof(list_t));
    list_t *new_node = malloc(sizeof(list_t));

    node->next = malloc(sizeof(list_t *) * 6);
    for (int i = 0; i < 5; i++)
        node->next[i] = new_node;
    node->next[5] = NULL;
    node->next = remove_link(node->next);
    cr_assert_eq(node_size(node->next), 4);
    free(node->next);
    free(node);
    free(new_node);
}
