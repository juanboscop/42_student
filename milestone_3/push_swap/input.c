/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpavia <jpavia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:24:57 by bosco             #+#    #+#             */
/*   Updated: 2025/01/22 14:18:14 by jpavia           ###   ########.fr       */
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

int	ft_atoi(const char *str, int *error)
{
	long long	num;
	int			i;
	int			np;

	num = 0;
	i = 0;
	np = 1;
	*error = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			np = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if ((np == 1 && num > INT_MAX) || (np == -1 && -num < INT_MIN))
			*error = 1;
		i++;
	}
	return ((int)(np * num));
}

int	parse_arguments(int argc, char **argv, t_stack *a)
{
	int	i;
	int	num;
	int	j;
	int	error;

	i = 1;
	a->size = 0;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (-1);
		error = 0;
		num = ft_atoi(argv[i++], &error);
		if (error == 1)
			return (-1);
		j = 0;
		while (j < a->size)
		{
			if (a->arr[j] == num)
				return (-1);
			j++;
		}
		a->arr[a->size++] = num;
	}
	return (0);
}
