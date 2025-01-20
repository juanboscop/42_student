# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpavia <jpavia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 19:19:51 by bosco             #+#    #+#             #
#    Updated: 2025/01/20 15:19:25 by jpavia           ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME_SERVER = server
NAME_CLIENT = client

SRC_SERVER = server.c 
SRC_CLIENT = client.c 

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

FT_PRINTF_DIR = ft_printf_42
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

all: $(FT_PRINTF_LIB) $(NAME_SERVER) $(NAME_CLIENT)

$(FT_PRINTF_LIB):
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME_SERVER): $(OBJ_SERVER) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(FT_PRINTF_LIB) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(FT_PRINTF_LIB) -o $(NAME_CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all
