# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bosco <bosco@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 19:19:51 by bosco             #+#    #+#              #
#    Updated: 2024/12/18 12:57:04 by bosco            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME_SERVER = server
NAME_CLIENT = client

SRC_SERVER = server.c 
SRC_CLIENT = client.c ft_itoa.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all
