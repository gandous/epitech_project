##
## EPITECH PROJECT, 2018
## make file
## File description:
## make
##

SRC	=	main.c				\
		errors/error.c			\
		errors/error1.c			\
		spe_bistro.c			\
		eval_expr/eval_expr.c		\
		eval_expr/sum_fac.c		\
		eval_expr/parenthesis.c		\
		eval_expr/str_editor.c		\
		infin_add/add_sub.c		\
		infin_add/disp_less.c		\
		infin_add/compatibility.c	\
		infin_multi/calc_multi.c	\
		infin_multi/main_multi.c	\
		infin_div_mod/calc_div.c	\
		infin_div_mod/calc_sup_div.c	\
		infin_div_mod/main_div.c

CFLAGS	=	-L./lib/my -lmy -I./include

NAME	=	calc

all:	$(NAME)

$(NAME):
	make -C lib/my
	gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
	make clean -C lib/my
	rm -f *~

fclean: clean
	make fclean -C lib/my
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
