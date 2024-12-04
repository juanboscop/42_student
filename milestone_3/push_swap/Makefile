# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpavia <jpavia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 16:06:12 by bosco             #+#    #+#              #
#    Updated: 2024/12/04 12:15:35 by jpavia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./ft_printf_42

# Executable name
NAME = push_swap

# Source files
SRC = push_swap.c input.c operation_push.c operation_swap.c \
      operation_rotate.c operation_r_rotate.c radix_sort.c \
      sort_utils.c
OBJ = $(SRC:.c=.o)

# Path to ft_printf_42
FT_PRINTF_PATH = ./ft_printf_42
FT_PRINTF_LIB = $(FT_PRINTF_PATH)/libftprintf.a

# Default rule
all: $(NAME)

# Build the executable and link with libftprintf.a
$(NAME): $(OBJ) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(FT_PRINTF_LIB)

# Rule to build libftprintf.a by calling the ft_printf_42 Makefile
$(FT_PRINTF_LIB):
	make -C $(FT_PRINTF_PATH)

# Compile .c files to .o files
%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJ)
	make clean -C $(FT_PRINTF_PATH)

# Clean up all files
fclean: clean
	rm -f $(NAME)
	make fclean -C $(FT_PRINTF_PATH)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
