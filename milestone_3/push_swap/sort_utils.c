/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:24:46 by bosco             #+#    #+#             */
/*   Updated: 2024/12/03 15:24:48 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_stack_to_temp(t_stack *stack, int *temp_arr)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		temp_arr[i] = stack->arr[i];
		i++;
	}
}

void	sort_temp_array(int *temp_arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (temp_arr[j] > temp_arr[j + 1])
			{
				tmp = temp_arr[j];
				temp_arr[j] = temp_arr[j + 1];
				temp_arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	map_numbers_to_indices(t_stack *stack, int *temp_arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (stack->arr[i] == temp_arr[j])
			{
				stack->indices[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	map_indices(t_stack *stack)
{
	int	temp_arr[1000];

	copy_stack_to_temp(stack, temp_arr);
	sort_temp_array(temp_arr, stack->size);
	map_numbers_to_indices(stack, temp_arr);
}