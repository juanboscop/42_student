/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:02:36 by bosco             #+#    #+#             */
/*   Updated: 2024/12/03 16:58:27 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack *stack_a, t_stack *stack_b, int lower, int upper)
{
	int	chunk_size;
	int	pushed;

	chunk_size = upper - lower;
	pushed = 0;
	while (pushed < chunk_size)
	{
		if (stack_a->indices[0] >= lower && stack_a->indices[0] < upper)
		{
			push_b(stack_a, stack_b);
			pushed++;
			if (stack_b->indices[0] < lower + chunk_size / 2)
				rotate_b(stack_b);
		}
		else
			rotate_a(stack_a);
	}
}

int	find_max_index_pos(t_stack *stack_b)
{
	int	max_idx;
	int	pos;
	int	i;

	max_idx = stack_b->indices[0];
	pos = 0;
	i = 1;
	while (i < stack_b->size)
	{
		if (stack_b->indices[i] > max_idx)
		{
			max_idx = stack_b->indices[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

void	sort_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	pos;

	while (stack_b->size > 0)
	{
		pos = find_max_index_pos(stack_b);
		if (pos <= stack_b->size / 2)
		{
			while (pos-- > 0)
				rotate_b(stack_b);
		}
		else
		{
			pos = stack_b->size - pos;
			while (pos-- > 0)
				reverse_rotate_b(stack_b);
		}
		push_a(stack_a, stack_b);
	}
}

void	radix_sort_two(t_stack *a, t_stack *b, int nc, int cs)
{
	int	i;
	int	upper;
	int	lower;
	int	total_size;

	i = 0;
	total_size = a->size;
	while (i < nc)
	{
		lower = i * cs;
		upper = (i + 1) * cs;
		if (upper > total_size)
			upper = total_size;
		push_to_b(a, b, lower, upper);
		i++;
	}
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	num_chunks;
	int	chunk_size;
	int	total_size;

	map_indices(stack_a);
	total_size = stack_a->size;
	if (total_size <= 100)
		num_chunks = 5;
	else
		num_chunks = 11;
	chunk_size = (total_size + num_chunks - 1) / num_chunks;
	radix_sort_two(stack_a, stack_b, num_chunks, chunk_size);
	sort_back_to_a(stack_a, stack_b);
}
