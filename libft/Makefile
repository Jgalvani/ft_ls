# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/14 17:10:37 by jgalvani          #+#    #+#              #
#    Updated: 2017/05/09 14:07:26 by jgalvani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	   ft_toupper.c ft_tolower.c ft_strlen.c ft_atoi.c ft_strcmp.c \
	   ft_strequ.c ft_memcmp.c ft_strnequ.c ft_itoa.c ft_strdel.c ft_strdup.c \
	   ft_strnew.c ft_strtrim.c ft_strcpy.c ft_strchr.c ft_strrchr.c \
	   ft_strsplit.c ft_strcat.c ft_strmap.c ft_strjoin.c ft_strncpy.c \
	   ft_strstr.c ft_strncat.c ft_strlcat.c ft_strmapi.c ft_strsub.c \
	   ft_strnstr.c ft_putnbr.c ft_putchar.c ft_strclr.c ft_memdel.c \
	   ft_putstr.c ft_putendl.c ft_memalloc.c ft_bzero.c ft_putnbr_fd.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_striter.c ft_lstadd.c \
	   ft_memset.c ft_memchr.c ft_memcpy.c ft_lstiter.c ft_memmove.c \
	   ft_memccpy.c ft_lstdel.c ft_lstdelone.c ft_lstmap.c ft_lstnew.c \
	   ft_striteri.c ft_strncmp.c ft_countwords.c ft_isnoint.c \
	   ft_iswhitespace.c ft_strlower.c ft_range.c ft_countnumbers.c \
	   get_next_line.c ft_putunbr.c ft_uitoa_base.c putcharlen.c \
	   ft_strrev.c print_add.c countnbr_base.c ft_countunbr.c ft_countonbr.c \
	   ft_countxnbr.c ft_putlim.c ft_putulim.c print_bits.c print.c \
	   ret_bits.c put_wchar.c bin_to_dec.c ft_countmax.c ft_countumax.c \
	   ft_strndup.c error.c free_list.c


OBJS = $(SRCS:.c=.o)

HDRS = libft.h get_next_line.h ./ft_printf/ft_printf.h

FLGS = -Wall -Wextra -Werror

.PHONY: all fclean clean re

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	gcc -c  $(FLGS) $(SRCS)
	make -C ./ft_printf/
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)
	make clean -C ./ft_printf/

fclean:	clean
	rm -rf libft.a
	make fclean -C ./ft_printf/

re: fclean all
