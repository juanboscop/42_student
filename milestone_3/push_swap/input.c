/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:24:57 by bosco             #+#    #+#             */
/*   Updated: 2024/11/24 14:30:59 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_number(char *str) {
	// Check if the string is a valid number
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)  // Empty string after sign
		return 0;
	while (*str) {
		if (!isdigit(*str))
			return 0;
		str++;
	}
	return 1;
}

int		parse_arguments(int argc, char **argv, t_stack *a)
{
	int	i;
	int	num;
	int	j;

	i = 1;
	if (argc < 2)
		return (-1);
	a->size = 0;
	while (i < argc)
	{
		if (!is_number(argv[i]))
		{
			printf("%s = Only intergers allowed!\n\n", R_MSG);
			return (-1);
		}
		num = atoi(argv[i]);
		if ((num == INT_MAX && strcmp(argv[i], "2147483647") != 0) ||
			(num == INT_MIN && strcmp(argv[i], "-2147483648") != 0))
		{
			printf("%s = Number exceeded interger size!\n\n", R_MSG);
			return (-1);
		}
		j = 0;
		while (j < a->size)
		{
			if (a->arr[j] == num)
			{
				printf("%s = There are duplicates in the stack!\n\n", R_MSG);
				return (-1);
			}
			j++;
		}
		a->arr[a->size] = num;
		a->size++;
		i++;
	}
	return (0);
}

