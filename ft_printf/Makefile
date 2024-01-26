# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlefebvr <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 15:56:07 by tlefebvr          #+#    #+#              #
#    Updated: 2021/12/06 15:43:26 by tlefebvr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS	= -Wall -Wextra -Werror -I./includes

SRCS =	ft_printf.c \
		ft_print_hex.c \
		ft_print_ptr.c \
		ft_print_unsigned.c \
		ft_print_utils.c \
		ft_itoa.c \
		ft_putchar_fd.c

SRCO = $(SRCS:.c=.o)

CC = gcc

RM = rm -f

all: $(NAME)

$(NAME): $(SRCO)
	gcc $(CFLAGS) -c $(SRCS)
	ar cr $(NAME) $(SRCO)

clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re: clean fclean all

.PHONY: clean fclean re

