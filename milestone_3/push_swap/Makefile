# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bosco <bosco@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 16:06:12 by bosco             #+#    #+#              #
#    Updated: 2024/11/24 19:25:57 by bosco            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Executable name
NAME = push_swap

# Source files
SRC = main.c input.c operation_push.c push_swap.c operation_swap.c \
	  operation_rotate.c operation_r_rotate.c radix_sort.c
OBJ = $(SRC:.c=.o)

# Default rule
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Compile .c files to .o files
%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJ)

# Clean up all files
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all
