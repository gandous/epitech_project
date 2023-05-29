##
## EPITECH PROJECT, 2018
## matchstick | Makefile
## File description:
## Makefile
##

NAME	=	matchstick

SRC	=	        main.c		\
				matchstick.c\
				manage_table.c\
				print.c\
				player_manage.c\
				get_number.c\
				my_put_nbr.c\
				manage_stick.c\
				manage_ia.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-I./include -g

all:			$(NAME)

$(NAME):	$(OBJ)
		gcc -c $(SRC) $(CFLAGS)
		gcc -o $(NAME) $(CFLAGS) $(OBJ)
		rm $(OBJ)

clean :
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
