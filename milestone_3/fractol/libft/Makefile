# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bosco <bosco@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 17:49:46 by bosco             #+#    #+#              #
#    Updated: 2024/12/09 17:54:57 by bosco            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# Source files
SRCS = ft_atof.c ft_putstr.c ft_strncmp.c

# Object files
OBJS = $(SRCS:.c=.o)

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Archive command
AR = ar rcs

# Targets
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re