# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlefebvr <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 11:15:36 by tlefebvr          #+#    #+#              #
#    Updated: 2022/02/23 11:25:06 by tlefebvr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = so_long
LIBFT = libft.a
MLX = libmlx.a
PRINTF = libftprintf.a
CFlAGS = -Wall -Wextra -Werror -I./includes

SRCS = ft_check_file.c \
	   ft_close.c \
	   ft_event.c \
	   ft_get_file.c \
	   ft_split_ln.c \
	   ft_sprite.c \
	   init_map.c \
	   init_sprite.c \
	   init_xpm.c \
	   reload.c \
	   main.c 

LIBFTPATH = libft/

MLXPATH = mlxOpen/

PRINTFPATH = ft_printf/

AX_FLAGS = mlxOpen/libmlx.a libft/libft.a ft_printf/libftprintf.a


SRCO = $(SRCS:.c=.o)

CC = gcc

FRAME = -framework OpenGL -framework AppKit

RM = rm -f

all: $(NAME)

$(NAME): $(SRCO)
	@make -C ${LIBFTPATH}
	@make -C ${MLXPATH}
	@make -C ${PRINTFPATH}
	$(CC) $(CFLAGS) $(AX_FLAGS) $(SRCO) $(FRAME)  -o $(NAME)

clean:
	$(RM) $(SRCO)
	#make clean -C $(LIBFTPATH)
#	make clean -C $(PRINTFPATH)

fclean: clean
	#make clean -C $(MLXPATH)
	#make fclean -C  $(LIBFTPATH)
	#make fclean -C $(PRINTFPATH)
	$(RM) $(NAME)

re: clean fclean all

.PHONY: clean fclean all
