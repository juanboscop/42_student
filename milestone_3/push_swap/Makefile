# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bosco <bosco@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 16:06:12 by bosco             #+#    #+#              #
#    Updated: 2025/01/31 19:34:42 by bosco            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./ft_printf_42

# Executable name
NAME = push_swap

# Source files
SRC = push_swap.c input.c operation_push.c operation_swap.c \
      operation_rotate.c operation_r_rotate.c radix_sort.c \
      sort_utils.c push_smallest_to_top.c sort_small_stack.c \
	  free_split.c
OBJ = $(SRC:.c=.o)

# Path to ft_printf_42 and its libs
FT_PRINTF_PATH = ./ft_printf_42
FT_PRINTF_LIB = $(FT_PRINTF_PATH)/libftprintf.a
LIBFT_LIB = $(FT_PRINTF_PATH)/libft/libft.a  # Add this line

# Default rule
all: $(NAME)

# Link both libftprintf.a AND libft.a
$(NAME): $(OBJ) $(FT_PRINTF_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(FT_PRINTF_LIB) $(LIBFT_LIB)  # Updated

# Build libftprintf.a and libft.a
$(FT_PRINTF_LIB):
	make -C $(FT_PRINTF_PATH)

$(LIBFT_LIB):  # Ensure libft.a is built
	make -C $(FT_PRINTF_PATH)/libft

# Compile .c files to .o files
%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(FT_PRINTF_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(FT_PRINTF_PATH)

re: fclean all

.PHONY: all clean fclean re