/*
** EPITECH PROJECT, 2019
** tests_parser.c
** File description:
** tests_parser.c
*/

#include "lemin.h"

Test(chain_list, test_fill_node, .init = redirect_all_std)
{
    char *str = my_strcpy("2 0 5");
    chain_list_t *chain_list = malloc(sizeof(chain_list_t));
    int ret = fill_node(chain_list, str);

    cr_assert(ret == MY_SUCCESS);
    cr_assert(chain_list->node_start);
    cr_assert_str_eq(chain_list->node_start->id, "2");
    cr_assert_eq(chain_list->node_start->x, 0);
    cr_assert_eq(chain_list->node_start->y, 5);
    free(chain_list);
    free(str);
}

Test(chain_list, add_node, .init = redirect_all_std)
{
    chain_list_t *chain_list = malloc(sizeof(chain_list_t));
    list_t *list = malloc(sizeof(list_t));
    list_t *list2 = malloc(sizeof(list_t));

    list->id = "3";
    list->x = 3;
    list->y = 2;
    list2->id = "2";
    list2->x = 4;
    list2->y = 2;
    chain_list->node_start = list2;
    add_node(chain_list, list);
    cr_assert_str_eq(chain_list->node_start->id, list2->id);
    cr_assert_eq(chain_list->node_start->x, list2->x);
    cr_assert_eq(chain_list->node_start->y, list2->y);
    cr_assert_str_eq(chain_list->node_start->node_next->id, list->id);
    cr_assert_eq(chain_list->node_start->node_next->x, list->x);
    cr_assert_eq(chain_list->node_start->node_next->y, list->y);
    free(chain_list);
    free(list);
    free(list2);
}
