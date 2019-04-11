# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jvisser <jvisser@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/12 12:07:57 by jvisser        #+#    #+#                 #
#    Updated: 2019/02/27 12:25:41 by jvisser       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a
C_FILES =	ft_strcpy.c		ft_putendl.c	ft_sqrt.c
O_FILES =	${C_FILES:.c=.o}

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(C_FILES)
	ar rcs $(NAME) $(O_FILES)

clean:
	/bin/rm -f $(O_FILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
