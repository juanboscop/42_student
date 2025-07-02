# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bosco <bosco@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 13:32:14 by bosco             #+#    #+#              #
#    Updated: 2025/05/06 13:17:10 by bosco            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CCFLAGS = -Wall -Wextra -Werror

SRC =	ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_atoi.c  \
		ft_memset.c \
		ft_split.c \
		ft_substr.c \
		ft_strchr.c \
		ft_strlen.c ft_atol.c ft_bzero.c ft_strcmp.c

OBJ = $(SRC:.c=.o)
LIB = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -I. -c -o $@ $<

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re