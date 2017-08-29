# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/14 17:10:37 by jgalvani          #+#    #+#              #
#    Updated: 2017/08/24 15:38:40 by jgalvani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC_DIR = src

SRCS = main.c dir.c error.c stat.c list.c sort.c ascii.c time.c print.c \
		large.c link.c permissions.c regular.c

OBJ_DIR = objects

OBJS = $(SRCS:.c=.o)

HDRS = ./libft/libft.h ft_ls.h

SRC_PATH = $(addprefix $(SRC_DIR)/,$(SRCS))
OBJ_PATH = $(addprefix $(OBJ_DIR)/,$(OBJS))

FLGS = -Wall -Wextra -Werror

.PHONY: all fclean clean re

all: $(NAME)

$(NAME): $(SRC_PATH) $(HDRS)
	@mkdir $(OBJ_DIR) 2> /dev/null || true
	@echo "\033[0;40;32mCreating objects." 2> /dev/null
	@gcc -c  $(FLGS) $(SRC_PATH)
	@mv $(OBJS) $(OBJ_DIR) 2> /dev/null
	@echo "Compiling libft." 2> /dev/null
	@make -C ./libft/ 2> /dev/null
	@echo "Compiling ft_ls." 2> /dev/null
	@gcc $(FLGS) -o $(NAME) $(OBJ_PATH) ./libft/libft.a \
		./libft/ft_printf/libftprintf.a
	@echo "\033[0m" 2> /dev/null

clean:
	@echo "\033[0;40;31mErasing objects."
	@rm -rf $(OBJ_PATH) 2> /dev/null
	@rmdir $(OBJ_DIR) 2> /dev/null || true
	@echo "Cleaning libft."
	@make clean -C ./libft/ 2> /dev/null
	@echo "\033[0" 2> /dev/null

fclean:	clean
	@echo "\033[0;40;35mErasing ft_ls."
	@rm -rf ft_ls 2> /dev/null
	@make fclean -C ./libft/ 2> /dev/null
	@echo "\033[0m" 2> /dev/null

re: fclean all
