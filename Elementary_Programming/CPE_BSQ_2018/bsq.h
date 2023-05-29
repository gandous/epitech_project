/*
** EPITECH PROJECT, 2018
** bsq header
** File description:
** header for bsg
*/

#ifndef BSQ_H_
#define BSQ_H_

typedef struct file_size{
    int width;
    int height;
} file_size_t;

typedef struct array_pos{
    int x;
    int y;
} array_pos_t;

typedef struct square_coord{
    int x;
    int y;
    int size;
} square_coord_t;

file_size_t *calc_file_size(char const *);
char *mem_alloc(char const *, char const *);
char **mem_dup_2d_array(char **, int, int);
char **mem_alloc_2d_array(int, int);
char **load_2d_array_from_file(char const *, int, int);
int find_big_square(char **map, file_size_t *fsize, array_pos_t *pos, int size);
int is_square_of_size(char **, int, int, int);
int my_strlen(char const *);
void my_putstr(char const *, int);
int my_getnbr(char const *);
char **replace_map(char **, square_coord_t *);
int number_size(int);
void my_putchar(char);
void display_map(char **, file_size_t *);

#endif
