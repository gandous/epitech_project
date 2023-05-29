##
## EPITECH PROJECT, 2018
## 102architect
## File description:
## main Makefile
##

SRC	=	main.c			\
		pushswap.c		\
		list_gest.c		\
		list_opp.c		\
		sort.c			\
		print.c			\
		sort_neg.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./

NAME	=	push_swap

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -c $(SRC) $(CFLAGS)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re:	clean fclean all

.PHONY:	all clean fclean re
