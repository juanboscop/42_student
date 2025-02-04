/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:24:57 by bosco             #+#    #+#             */
/*   Updated: 2025/02/04 18:39:09 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_digit(char c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	process_token(t_stack *a, char *token, int *error)
{
	int	num;
	int	i;

	i = 0;
	if (!is_number(token) || a->size >= 1000)
		return (-1);
	num = ft_atoi(token, error);
	if (*error)
		return (-1);
	while (i < a->size)
	{
		if (a->arr[i] == num)
			return (-1);
		i++;
	}
	a->arr[a->size++] = num;
	return (0);
}

static int	process_arg(t_stack *a, char *arg)
{
	char	**tokens;
	int		j;
	int		error;

	tokens = ft_split(arg, ' ');
	if (!tokens)
		return (-1);
	j = -1;
	error = 0;
	while (tokens[++j])
	{
		if (process_token(a, tokens[j], &error) == -1)
		{
			free_tokens(tokens);
			return (-1);
		}
	}
	free_tokens(tokens);
	return (0);
}

int	parse_arguments(int argc, char **argv, t_stack *a)
{
	int	i;

	i = 0;
	a->size = 0;
	while (++i < argc)
		if (process_arg(a, argv[i]) == -1)
			return (-1);
	return (0);
}
