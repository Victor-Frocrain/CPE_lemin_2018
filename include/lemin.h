/*
** EPITECH PROJECT, 2018
** lemin.h
** File description:
** lemin.h
*/

#ifndef LEMIN_H_
#define LEMIN_H_

#include "my.h"
#include "my_printf.h"
#include "get_next_line.h"
/* Chain list */
typedef struct list {
    int nb_link;
    char *id;
    int x;
    int y;
    struct list *node_next;
    struct list **next;
}list_t;

typedef struct chain_list {
    list_t *node_start;
    list_t *start;
    list_t *end;
}chain_list_t;
/* Chain_list */
/* Project structure */
typedef struct ant_s {
    int parser_state;
    char **tunnels;
    char *first_link;
    int nb_ant;
    chain_list_t *chain_list;
}ant_t;
/* Project structure */
/* Parser prototype */
bool is_node(char *str, chain_list_t *chain_list);
bool is_node_value(chain_list_t *chain_list, int x, int y, char *id);
bool is_int(char *str);
/* Parser prototype */
/* Manage input */
char **add_tunnels(char **tunnels, char *id, char *id2);
char *remove_space(char *str, int ref);
bool is_useless_char(char *str, int i);
char *manage_input(bool is_linked, bool is_start, bool is_end);
/* Manage input */
/* Fill chain_list */
void add_node(chain_list_t *chain_list, list_t *list);
int fill_first_node(chain_list_t *chain_list);
int fill_last_node(chain_list_t *chain_list);
int fill_node(chain_list_t *chain_list, char *str);
/* Fill chain_list */
/* Link rooms */
bool redefined_list(list_t *list, int size, list_t *next_list);
bool add_next(list_t *list, list_t *list2);
bool is_list_next(list_t *list, list_t *list2);
list_t *find_id_in_chain_list(chain_list_t *chain_list, char *id);
bool link_list(chain_list_t *chain_list, char *id, char *id2);
/* Link rooms */
/* Main function */
bool is_str_link(char *str);
int link_chain_list(chain_list_t *chain_list, char *str, char ***tunnels,
bool *is_error);
void fill_chain_list(chain_list_t *chain_list, char ***tunnels, bool *is_error);
int lemin(void);
/* Main function */
/* Fill tab */
ant_t compute_nb_path(ant_t *ant);
ant_t search_the_path(ant_t *ant, list_t *node, int j, char *id);
ant_t fill_tab(ant_t *ant);
ant_t search_path(ant_t *ant);
/* Fill tab */
/* My realloc int * */
int my_chartablen(char **map);
int my_intlen(int *tab);
int my_inttab(int **tab);
int *my_intalloc(int *tab, int pos);
int **my_taballoc(int **tab);
/* My realloc int * */
/* Display_graph */
bool display_room(chain_list_t *chain_list);
bool display_tunnels(char **tunnels, bool ret);
int display_graph(ant_t *ant);
/* Display_graph */
/* Search path */
bool is_already_seen(char **way, char *id);
char **add_way(char **actual_way, char *pos);
int node_size(list_t **node);
list_t **remove_link(list_t **node);
bool pathfinding(list_t *list, char *end_id, char **way);
/* Search path */
/* Display move */
int way_len(chain_list_t *chain_list);
char *search_pos(ant_t *ant, int count);
void display_results(ant_t *ant, int k, int i, int way_lenght);
void display_move(ant_t *ant);
/* Display move */
/* Destroy ressource */
void destroy_node(list_t *list);
void destroy_ress(ant_t *ant);
/* Destroy ressource */
/* Parsing nb ant */
bool get_nb_ant(ant_t *ant);
/* Parsing nb ant */
/* Parsing room */
bool is_get_map_state_changed(char *str);
bool get_room(ant_t *ant);
/* Parsing room */
/* Parsing link */
bool link_room(ant_t *ant);
/* Parsing link */
#endif /* LEMIN_H_ */
