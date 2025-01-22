/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpavia <jpavia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:06:05 by bosco             #+#    #+#             */
/*   Updated: 2025/01/22 14:20:00 by jpavia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf_42/ft_printf.h"
#include "ft_printf_42/libft/libft.h"

// int operation_count = 0;
	// operation_count++:
void	log_operation(const char *op_name)
{
	printf("%s\n", op_name);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->arr[i] > stack->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	print_stack(const char *name, t_stack *stack)
{
	int	i;

	printf("%s: ", name);
	i = 0;
	while (i < stack->size)
	{
		printf("%d ", stack->arr[i]);
		i++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (-1);
	if (parse_arguments(argc, argv, &stack_a) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	stack_b.size = 0;
	if (is_sorted(&stack_a))
		return (0);
	radix_sort(&stack_a, &stack_b);
	return (0);
}
// printf("Initial stacks:\n");
// print_stack("Stack A", &stack_a);
// print_stack("Stack B", &stack_b);
// printf("\nPerforming Radix Sort:\n");
//after radix;
// printf("\nSorted stack:\n");
// print_stack("Stack A", &stack_a);
// printf("Stack B: (should be empty)\n");
// print_stack("Stack B", &stack_b);
// printf("\nTotal operations: %d\n", operation_count);