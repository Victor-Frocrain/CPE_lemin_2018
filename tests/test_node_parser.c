/*
** EPITECH PROJECT, 2019
** tests_parser.c
** File description:
** tests_parser.c
*/

#include "lemin.h"

Test(parser, test_node_not_int, .init = redirect_all_std)
{
    char *str = my_strcpy("2 ki 3");
    chain_list_t *chain_list = malloc(sizeof(chain_list_t));
    list_t *list = malloc(sizeof(list_t));

    chain_list->node_start = list;
    cr_assert(!is_node(str, chain_list));
    free(chain_list);
    free(list);
    free(str);
}

Test(parser, test_node_right, .init = redirect_all_std)
{
    char *str = my_strcpy("2 4 3");
    chain_list_t *chain_list = malloc(sizeof(chain_list_t));
    list_t *list = malloc(sizeof(list_t));

    list->id = "3";
    list->x = 2;
    list->y = 2;
    list->node_next = NULL;
    chain_list->node_start = list;
    cr_assert(is_node(str, chain_list));
    free(chain_list);
    free(list);
    free(str);
}

Test(parser, test_node_id_already_exist, .init = redirect_all_std)
{
    char *str = my_strcpy("2 4 3");
    chain_list_t *chain_list = malloc(sizeof(chain_list_t));
    list_t *list = malloc(sizeof(list_t));

    list->id = "2";
    list->x = 2;
    list->y = 2;
    list->node_next = NULL;
    chain_list->node_start = list;
    cr_assert(!is_node(str, chain_list));
    cr_assert_stderr_eq_str("Error: This id is already used\n");
    free(chain_list);
    free(list);
    free(str);
}

Test(parser, test_node_pos_already_exist, .init = redirect_all_std)
{
    char *str = my_strcpy("2 4 3");
    chain_list_t *chain_list = malloc(sizeof(chain_list_t));
    list_t *list = malloc(sizeof(list_t));

    list->id = "3";
    list->x = 4;
    list->y = 3;
    list->node_next = NULL;
    chain_list->node_start = list;
    cr_assert(!is_node(str, chain_list));
    cr_assert_stderr_eq_str("Error: This position is already used\n");
    free(chain_list);
    free(list);
    free(str);
}

Test(parser, test_node_input_inccorect, .init = redirect_all_std)
{
    char *str = my_strcpy("2 4 3 4");
    chain_list_t *chain_list = malloc(sizeof(chain_list_t));
    list_t *list = malloc(sizeof(list_t));

    list->id = "3";
    list->x = 4;
    list->y = 3;
    list->node_next = NULL;
    chain_list->node_start = list;
    cr_assert(!is_node(str, chain_list));
    cr_assert_stderr_eq_str("Error: the input is incorrect should \
have 3 arguments\n");
    free(chain_list);
    free(list);
    free(str);
}
