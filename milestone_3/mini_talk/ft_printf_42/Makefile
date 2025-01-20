# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpavia <jpavia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/27 20:10:54 by bosco             #+#    #+#              #
#    Updated: 2025/01/20 15:44:39 by jpavia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CCFLAGS = -Wall -Wextra -Werror -I./libft

SRC = ft_printf.c \
      ft_puthex_upper.c \
      ft_puthex_lower.c \
	  ft_puthex_lower_long.c \
      ft_putptr.c \
      ft_putnbr_unsigned_fd.c

OBJ = $(SRC:.c=.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

# Add the necessary object files from libft
LIBFT_OBJS = $(LIBFT_PATH)/ft_putchar_fd.o \
             $(LIBFT_PATH)/ft_putstr_fd.o \
             $(LIBFT_PATH)/ft_putnbr_fd.o \
			 $(LIBFT_PATH)/ft_atoi.o \
			 $(LIBFT_PATH)/ft_memset.o

COMPILE_LIB = ar rcs
REMOVE = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBFT_OBJS)
	$(COMPILE_LIB) $(NAME) $(OBJ) $(LIBFT_OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH)

%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	$(REMOVE) $(OBJ)
	make clean -C $(LIBFT_PATH)

fclean: clean
	$(REMOVE) $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re
