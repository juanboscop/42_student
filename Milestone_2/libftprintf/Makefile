# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bosco <bosco@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/27 20:10:54 by bosco             #+#    #+#              #
#    Updated: 2024/11/26 17:39:23 by bosco            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CCFLAGS = -Wall -Wextra -I./libft

SRC =	ft_printf.c \
		ft_puthex_upper.c \
		ft_puthex_lower.c \
		ft_putptr.c \
		ft_putnbr_unsigned_fd.c

OBJ = $(SRC:.c=.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
COMPILE_LIB = ar rcs
REMOVE = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) .
	$(COMPILE_LIB) $(NAME) $(OBJ) libft.a
	rm libft.a     

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	$(REMOVE) $(OBJ)
	make clean -C $(LIBFT_PATH)

fclean: clean
	$(REMOVE) $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re