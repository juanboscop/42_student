/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:55:50 by bosco             #+#    #+#             */
/*   Updated: 2024/11/24 19:24:12 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack *stack_a)
{
	int	i;
	int	temp;

	if (stack_a->size > 1)
	{
		i = stack_a->size - 1;
		temp = stack_a->arr[stack_a->size - 1];
		while (i > 0)
		{
			stack_a->arr[i] = stack_a->arr[i - 1];
			i--;
		}
		stack_a->arr[0] = temp;
	}
	log_operation("rra");
}

void	reverse_rotate_b(t_stack *stack_b)
{
	int	i;
	int	temp;

	if (stack_b->size > 1)
	{
		i = stack_b->size - 1;
		temp = stack_b->arr[stack_b->size - 1];
		while (i > 0)
		{
			stack_b->arr[i] = stack_b->arr[i - 1];
			i--;
		}
		stack_b->arr[0] = temp;
	}
	log_operation("rrb");
}

void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size > 1 && stack_b->size > 1)
	{
		reverse_rotate_a(stack_a);
		reverse_rotate_b(stack_b);
	}
	log_operation("rrr");
}
