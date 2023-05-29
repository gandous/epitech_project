##
## EPITECH PROJECT, 2018
## my ls | Makefile
## File description:
## Makefile
##

NAME	=	my_ls

SRC	=	        main.c     		\
				check_flag.c	\
				my_ls.c			\
				make_ls.c		\
				print.c			\
				text_gest.c		\
				flag_l.c		\
				my_put_nbr.c	\
				flag_t.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-I./include

all:			$(NAME)

$(NAME):	$(OBJ)
		gcc -c $(SRC) $(CFLAGS)
		gcc -o $(NAME) -g3 $(CFLAGS) $(OBJ)
		rm $(OBJ)

clean :
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
