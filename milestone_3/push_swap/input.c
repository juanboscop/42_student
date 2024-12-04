/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:24:57 by bosco             #+#    #+#             */
/*   Updated: 2024/12/03 20:43:40 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	if (*str == '-')
		return (0);
	if (*str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
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
		num = atoi(argv[i]);
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
