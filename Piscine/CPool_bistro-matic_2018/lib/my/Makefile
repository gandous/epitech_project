## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC	=	my_getnbr.c		\
		my_putchar.c		\
		my_put_nbr.c		\
		my_putstr.c		\
		my_strlen.c		\
		my_str_isnum.c		\
		my_strstr.c		\
		my_strcpy.c		\
		my_atoi.c		\
		str_isfac_sum.c		\
		str_isfac.c		\
		str_len.c		\
		my_isnum.c		\
		init_table.c		\
		char_isneg.c		\
		remove_zero.c		\
		str_cut.c		\
		result_isnul.c		\
		char_remove_sign.c	\
		char_issup.c		\
		str_finder.c

OBJ	=	$(SRC:.c=.o)

HEADER  =       my.h

NAME	=	libmy.a

all: $(NAME)

$(NAME):
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp $(HEADER) ../../include

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f  ../$(NAME)
	rm -f ../../include/$(HEADER)

re: 	fclean all

.PHONY:	all clean fclean re
