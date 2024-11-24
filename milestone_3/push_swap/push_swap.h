/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:06:09 by bosco             #+#    #+#             */
/*   Updated: 2024/11/24 19:43:06 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

# define R_MSG "\n\033[1;31mERROR\033[0m"

typedef struct s_stack {
	int arr[501];// Fixed-size array to hold the stack elements
	int size;// Current number of elements in the stack
} t_stack;

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
void	log_operation(const char *op_name);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);

#endif
