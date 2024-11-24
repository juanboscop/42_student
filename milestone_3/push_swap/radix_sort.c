/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:02:36 by bosco             #+#    #+#             */
/*   Updated: 2024/11/24 19:29:35 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void radix_sort(t_stack *stack_a, t_stack *stack_b) {
    int bit;
    int size;
    int i;

    size = stack_a->size;
    for (bit = 0; bit < 32; bit++) { // Iterate over all 32 bits
        i = 0;
        while (i < size) { // Process all elements in stack_a
            if ((stack_a->arr[0] >> bit) & 1) {
                // If the current bit is 1, rotate to the end of stack_a
                rotate_a(stack_a);
            } else {
                // If the current bit is 0, push to stack_b
                push_b(stack_a, stack_b);
            }
            i++;
        }
        // Push all elements back from stack_b to stack_a
        while (stack_b->size > 0) {
            push_a(stack_a, stack_b);
        }
    }
}
