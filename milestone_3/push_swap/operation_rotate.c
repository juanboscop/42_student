/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:55:32 by bosco             #+#    #+#             */
/*   Updated: 2024/11/24 19:23:33 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack_a)
{
	int i;
	int temp;

	i = 0;  
	if (stack_a->size > 1)
	{
		temp = stack_a->arr[0];
		while (i < stack_a->size - 1)
		{
			stack_a->arr[i] = stack_a->arr[i + 1];
			i++;
		}
		stack_a->arr[i] = temp;
	}
	log_operation("ra");
}

void	rotate_b(t_stack *stack_b)
{
	int i;
	int temp;

	i = 0;  
	if (stack_b->size > 1)
	{
		temp = stack_b->arr[0];
		while (i < stack_b->size - 1)
		{
			stack_b->arr[i] = stack_b->arr[i + 1];
			i++;
		}
		stack_b->arr[i] = temp;
	}
	log_operation("rb");
}

void    rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size > 1 && stack_b->size > 1)
	{
		rotate_a(stack_a);
		rotate_b(stack_b);
	}
	log_operation("rr");
}
