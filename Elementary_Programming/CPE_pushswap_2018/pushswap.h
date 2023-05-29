/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** header for pushswap
*/

#ifndef PUSHSWAP_H_
#define PUSHSWAP_H_

#define LIST_SIZE 33
#define PRINT_BUFFER 10000

typedef struct my_list_s {
    char value[LIST_SIZE];
    long val;
    struct my_list_s *next;
} my_list_t;

typedef struct print_s {
    char *buff;
    int index;
} print_t;

typedef struct map_data_s {
    int size;
    int index;
} map_data_t;

typedef struct list_data_s {
    my_list_t **list_a;
    my_list_t **list_b;
    my_list_t **end_a;
    my_list_t **end_b;
} list_data_t;

int pushswap(int argc, char **argv);
my_list_t *load_my_list(int argc, char **argv, long *size);
void swap_first(my_list_t **first);
void swap_list(my_list_t **list_src, my_list_t **list_dest);
void swap_to_last(my_list_t **list, my_list_t **last);
void swap_to_first(my_list_t **list);
void del_list(my_list_t *list);
int sort(my_list_t *list_a, my_list_t *list_b, long max);
void my_putstr(char *str, int size);
void add_to_buff(print_t *print_data, char *str);
void display_buffer(print_t *print_data);
void sort_neg(list_data_t *list, int lenght, print_t *p);
print_t *create_print_buff(void);
int check_sorted(my_list_t *list);

#endif
