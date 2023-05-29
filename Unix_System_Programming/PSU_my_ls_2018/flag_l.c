/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** flag_l
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <stdlib.h>
#include <grp.h>
#include "my_ls.h"

void print_value(int size)
{
    my_putstr("total ");
    my_put_nbr(size);
    my_putchar('\n');
}

void print_total_size(char *filepath)
{
    DIR *directory = opendir(filepath);
    struct dirent *content = NULL;
    struct stat file_data;
    int size = 0;
    char *path = NULL;

    if (directory == NULL)
        return;
    content = readdir(directory);
    while (content != NULL) {
        if (content->d_name[0] != '.') {
            path = create_dirpath(filepath, content->d_name);
            stat(path, &file_data);
            size = size + (file_data.st_blocks / 2);
            free(path);
        }
        content = readdir(directory);
    }
    print_value(size);
    closedir(directory);
}

void print_right(struct stat filestat)
{
    char *temp = NULL;

    temp = malloc(sizeof(char) * 12);
    if (temp == NULL)
        return;
    temp[11] = '\0';
    temp[10] = '.';
    (S_ISDIR(filestat.st_mode)) ? (temp[0] = 'd') : (temp[0] = '-');
    (filestat.st_mode & S_IRUSR) ? (temp[1] = 'r') : (temp[1] = '-');
    (filestat.st_mode & S_IWUSR) ? (temp[2] = 'w') : (temp[2] = '-');
    (filestat.st_mode & S_IXUSR) ? (temp[3] = 'x') : (temp[3] = '-');
    (filestat.st_mode & S_IRGRP) ? (temp[4] = 'r') : (temp[4] = '-');
    (filestat.st_mode & S_IWGRP) ? (temp[5] = 'w') : (temp[5] = '-');
    (filestat.st_mode & S_IXGRP) ? (temp[6] = 'x') : (temp[6] = '-');
    (filestat.st_mode & S_IROTH) ? (temp[7] = 'r') : (temp[7] = '-');
    (filestat.st_mode & S_IWOTH) ? (temp[8] = 'w') : (temp[8] = '-');
    (filestat.st_mode & S_IXOTH) ? (temp[9] = 'x') : (temp[9] = '-');
    my_putstr(temp);
    free(temp);
}

void print_sb(struct stat sb)
{
    struct passwd *user_pass = getpwuid(sb.st_uid);
    struct group *grp = getgrgid(sb.st_gid);

    print_right(sb);
    my_putchar(' ');
    my_put_nbr(sb.st_nlink);
    my_putstr(" ");
    my_putstr(user_pass->pw_name);
    my_putstr(" ");
    my_putstr(grp->gr_name);
    my_putstr(" ");
    my_put_nbr(sb.st_size);
    my_putstr(" ");
}

int make_l_flag(struct dirent *content, char *dir_path)
{
    struct stat sb;
    char *time_modif = NULL;
    char *file_name = create_dirpath(dir_path, content->d_name);

    if (content->d_name[0] == '.')
        return (0);
    if (stat(file_name, &sb) == -1)
        return (84);
    time_modif = ctime(&sb.st_mtime);
    print_sb(sb);
    for (int i = 4 ; time_modif[i] != '\0' && i < 16 ; i += 1)
        my_putchar(time_modif[i]);
    my_putstr(" ");
    my_putstr(content->d_name);
    my_putstr("\n");
    return (0);
}