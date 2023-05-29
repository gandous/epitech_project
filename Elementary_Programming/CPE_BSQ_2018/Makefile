##
## EPITECH PROJECT, 2018
## 101pong | Makefile
## File description:
## Makefile
##

NAME	=	bsq

SRC	=	norme_bsq.c     		\
                find_biggest_square.c           \
                calc_file_size.c                \
                is_square_of_size.c             \
                load_2d_array_from_file.c       \
                load_file_in_mem.c              \
                mem_alloc_2d_array.c            \
                mem_alloc.c                     \
                my_getnbr.c                     \
                my_putchar.c                    \
                my_putstr.c                     \
                replace_map.c			\
		my_strlen.c                     \
                display_map.c


OBJ		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):
		gcc -g3 -o $(NAME) $(SRC) -I./


clean :
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
