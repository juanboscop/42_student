/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:17:37 by bosco             #+#    #+#             */
/*   Updated: 2024/11/24 19:24:37 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_b->size > 0)
	{
		stack_a->size = stack_a->size + 1;
		i = stack_a->size;
		while (i > 0)
		{
			stack_a->arr[i] = stack_a->arr[i - 1];
			i--;
		}
		stack_a->arr[0] = stack_b->arr[0];
		i = 0;
		while (i < stack_b->size - 1)
		{
			stack_b->arr[i] = stack_b->arr[i + 1];
			i++;
		}
		stack_b->size = stack_b->size - 1;
	}
	log_operation("pa");
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_a->size > 0)
	{
		stack_b->size = stack_b->size + 1;
		i = stack_b->size - 1;
		while (i > 0)
		{
			stack_b->arr[i] = stack_b->arr[i - 1];
			i--;
		}
		stack_b->arr[0] = stack_a->arr[0];
		i = 0;
		while (i < stack_a->size - 1)
		{
			stack_a->arr[i] = stack_a->arr[i + 1];
			i++;
		}
		stack_a->size = stack_a->size - 1;
	}
	log_operation("pb");
}
