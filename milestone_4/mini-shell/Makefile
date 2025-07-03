# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bosco <bosco@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 12:17:48 by bosco             #+#    #+#              #
#    Updated: 2025/05/06 13:01:45 by bosco            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./ft_printf_42 -I./ft_printf_42/libft
SRCS = src/main.c src/parser.c src/tokenizer.c
OBJS = $(SRCS:.c=.o)

FT_PRINTF_DIR = ft_printf_42
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT = $(FT_PRINTF_DIR)/libft/libft.a

all: $(FT_PRINTF_LIB) $(NAME)

$(FT_PRINTF_LIB):
	make -C $(FT_PRINTF_DIR)

$(NAME): $(OBJS) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT_PRINTF_LIB) $(LIBFT) -lreadline

clean:
	rm -f $(OBJS)
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

