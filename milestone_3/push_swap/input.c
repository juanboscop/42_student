/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpavia <jpavia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:24:57 by bosco             #+#    #+#             */
/*   Updated: 2024/12/05 12:33:26 by jpavia           ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	unsigned int	num;
	int				i;
	int				np;

	np = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			np = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(np * num));
}

int	parse_arguments(int argc, char **argv, t_stack *a)
{
	int	i;
	int	num;
	int	j;

	i = 1;
	a->size = 0;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (-1);
		num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (-1);
		j = 0;
		while (j < a->size)
		{
			if (a->arr[j] == num)
				return (-1);
			j++;
		}
		a->arr[a->size] = num;
		a->size++;
		i++;
	}
	return (0);
}
