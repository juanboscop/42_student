/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:43:41 by bosco             #+#    #+#             */
/*   Updated: 2025/01/31 18:59:12 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->arr[0] > a->arr[1])
		swap_a(a);
}

void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

    top = a->arr[0];
    mid = a->arr[1];
    bot = a->arr[2];
	if (top > mid && mid < bot && bot > top)
		swap_a(a);
	else if (top > mid && mid < bot && bot < top)
		rotate_a(a);
	else if (top < mid && mid > bot && bot > top)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if (top > mid && mid > bot)
	{
		swap_a(a);
		reverse_rotate_a(a);
	}
	else if (top < mid && mid > bot && bot < top)
		reverse_rotate_a(a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	push_smallest_two(a, b);
	sort_three(a);
	push_a(a, b);
	push_a(a, b);
	if (a->arr[0] > a->arr[1])
		swap_a(a);
}

void	sort_small_stack(t_stack *a, t_stack *b, int size)
{
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
}


