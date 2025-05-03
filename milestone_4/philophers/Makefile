# philo/Makefile

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -I./ft_printf_42 -I./ft_printf_42/libft

SRCS = main.c parser.c init_simulation_data.c philo_acts.c monitor.c utils.c clean_up.c philo_acts_utils.c
OBJS = $(SRCS:.c=.o)

FT_PRINTF_DIR = ft_printf_42
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT = $(FT_PRINTF_DIR)/libft/libft.a

all: $(FT_PRINTF_LIB) $(NAME)

$(FT_PRINTF_LIB):
	make -C $(FT_PRINTF_DIR)

$(NAME): $(OBJS) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT_PRINTF_LIB) $(LIBFT)

clean:
	rm -f $(OBJS)
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
