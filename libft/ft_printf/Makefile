# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/15 18:57:56 by jgalvani          #+#    #+#              #
#    Updated: 2017/07/31 16:11:29 by jgalvani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c flags.c length.c parser.c num.c weird.c something.c last.c \
	  color.c

INC = ../libft.h ft_printf.h

OBJ = $(SRC:.c=.o)

FLG = -Wall -Wextra -Werror

.PHONY: all fclean clean re

all: $(NAME)

$(NAME): $(SRC) $(INC)
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f libftprintf.a

re: fclean all
