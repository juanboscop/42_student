/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:06:09 by bosco             #+#    #+#             */
/*   Updated: 2024/12/03 16:08:37 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>

// # define R_MSG "\n\033[1;31mERROR\033[0m"

typedef struct s_stack
{
	int	arr[1000]; // Fixed-size array to hold the stack elements
	int	indices[1000];
	int	size; // Current number of elements in the stack
}	t_stack;

extern int operation_count;

int		is_number(char *str);
int		parse_arguments(int argc, char **argv, t_stack *a);
void	swap_a(t_stack *stack_a);
void	swap_b(t_stack *stack_b);
void	swap_both(t_stack *stack_a, t_stack *stack_b);
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);
void	rotate_a(t_stack *stack_a);
void	rotate_b(t_stack *stack_b);
void	rotate_both(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_a(t_stack *stack_a);
void	reverse_rotate_b(t_stack *stack_b);
void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);
void	map_indices(t_stack *stack);
void	map_numbers_to_indices(t_stack *stack, int *temp_arr);
void	sort_temp_array(int *temp_arr, int size);
void	copy_stack_to_temp(t_stack *stack, int *temp_arr);
void	log_operation(const char *op_name);

#endif
