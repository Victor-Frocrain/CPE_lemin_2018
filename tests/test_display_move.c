/*
** EPITECH PROJECT, 2019
** test_display_move
** File description:
** test_display_move function
*/

#include "lemin.h"

Test(display_move, way_len, .init = redirect_all_std)
{
    chain_list_t *chain_list = malloc(sizeof(chain_list_t));
    list_t *node1 = malloc(sizeof(list_t));
    list_t *node2 = malloc(sizeof(list_t));
    list_t *node3 = malloc(sizeof(list_t));
    list_t *node4 = malloc(sizeof(list_t));

    node1->id = "S";
    node2->id = "a";
    node3->id = "b";
    node4->id = "E";
    chain_list->start = node1;
    chain_list->end = node1;
    node1->next[0] = node2;
    node2->next[0] = node3;
    node3->next[0] = node4;
    cr_assert_eq(way_len(chain_list), 3)
}
