/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_smallest_to_top.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:00:41 by bosco             #+#    #+#             */
/*   Updated: 2025/02/04 18:37:31 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_smallest_index(t_stack *s)
{
	int	i;
	int	min_idx;
	int	min_val;

	i = -1;
	min_idx = 0;
	min_val = s->arr[0];
	while (++i < s->size)
	{
		if (s->arr[i] < min_val)
		{
			min_val = s->arr[i];
			min_idx = i;
		}
	}
	return (min_idx);
}

static void	move_smallest_to_top(t_stack *a, int index)
{
	int	rotations;

	if (index <= a->size / 2)
	{
		rotations = index;
		while (rotations-- > 0)
			rotate_a(a);
	}
	else
	{
		rotations = a->size - index;
		while (rotations-- > 0)
			reverse_rotate_a(a);
	}
}

void	push_smallest_two(t_stack *a, t_stack *b)
{
	int	target_idx;

	target_idx = find_smallest_index(a);
	move_smallest_to_top(a, target_idx);
	push_b(a, b);
	target_idx = find_smallest_index(a);
	move_smallest_to_top(a, target_idx);
	push_b(a, b);
}
