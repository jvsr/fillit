# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jvisser <jvisser@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/30 11:52:06 by jvisser        #+#    #+#                 #
#    Updated: 2019/02/27 12:24:43 by jvisser       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		fillit
LIB =		-L libft -lft
FLAGS =		-Wall -Wextra -Werror
C_FILES =	src/main.c	src/utils.c	src/validate.c \
			src/map.c	src/fill.c
O_FILES =	main.o	utils.o	validate.o \
			map.o	fill.o
INCLUDES =	-I src/ -I libft/

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAGS) -c $(C_FILES) $(INCLUDES)
	gcc $(FLAGS) -o $(NAME) $(O_FILES) $(LIB) $(INCLUDES)

clean:
	make -C libft clean
	/bin/rm -f $(O_FILES)

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re: fclean all
