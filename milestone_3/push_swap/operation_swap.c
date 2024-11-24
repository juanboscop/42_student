/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:55:00 by bosco             #+#    #+#             */
/*   Updated: 2024/11/24 19:22:09 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack_a)
{
	int	temp;

	if (stack_a->size > 1)
	{
		temp = stack_a->arr[0];
		stack_a->arr[0] = stack_a->arr[1];
		stack_a->arr[1] = temp;
	}
	log_operation("sa");
}

void	swap_b(t_stack *stack_b)
{
	int	temp;

	if (stack_b->size > 1)
	{
		temp = stack_b->arr[0];
		stack_b->arr[0] = stack_b->arr[1];
		stack_b->arr[1] = temp;
	}
	log_operation("sb");
}

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size > 1 && stack_b->size > 1)
	{
		swap_a(stack_a);
		swap_b(stack_b);
	}
	log_operation("ss");
}
