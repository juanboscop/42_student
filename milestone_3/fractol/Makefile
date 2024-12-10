# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bosco <bosco@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 13:34:46 by bosco             #+#    #+#              #
#    Updated: 2024/12/10 18:43:54 by bosco            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #

NAME = fractol

# Source files
SRCS = main.c init.c fractal.c draw.c events.c clean_up.c handle_arrow.c

# Object files
OBJS = $(SRCS:.c=.o)

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx-linux

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

# Includes
INCLUDES = -I. -I$(LIBFT_DIR) -I$(MLX_DIR)

# Linker flags for MLX on Linux
# Adjust paths if necessary. On Linux, you often need to link against X11 and Xext.
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/X11/lib -lXext -lX11 -lm

# **************************************************************************** #
#                                   TARGETS                                    #
# **************************************************************************** #

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	@make -C ./libft

$(MLX):
	@make -C ./minilibx-linux

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) $(INCLUDES) -o $(NAME)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make clean -C ./libft
	@make clean -C ./minilibx-linux

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
	@make clean -C ./minilibx-linux

re: fclean all

.PHONY: all clean fclean re