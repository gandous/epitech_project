/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** my_ls
*/

#ifndef MY_LS_H_
#define MY_LS_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

typedef struct dir_name_s {
    char *name;
    struct dir_name_s *next;
} dir_name_t;

typedef struct file_name_s {
    time_t date;
    char *file_name;
    struct file_name_s *next;
} file_name_t;

char *check_flag(int argc, char **argv, int *nb_flag);
int my_ls(int argc, char **argv);
int make_ls(char *dir_path, char *flag, int print_n);
void my_putstr(char *str);
int my_strlen(char *str);
char *create_dirpath(char *start, char *end);
char *my_strcpy(char *src);
void my_put_nbr(int nb);
void my_putchar(char c);
int make_l_flag(struct dirent *content, char *dir_path);
void print_total_size(char *filepath);
int make_t_flag(char *dir_path);

#endif
