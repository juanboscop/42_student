/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:42:44 by bosco             #+#    #+#             */
/*   Updated: 2024/11/24 19:37:54 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int main(int argc, char **argv) {
//     t_stack a;

//     // Check the number of arguments does not exceed the static array size
//     if (argc - 1 > 500) {
//         printf("\n\033[1;31mERROR\033[0m = There are more than 500 numbers in the stack!\n\n");
//         return -1;
//     }

//     // Parse arguments
//     if (parse_arguments(argc, argv, &a) == -1) {
//         return -1;
//     }

//     // Print the stack
//     int i = 0;
//     while (i < a.size) {
//         printf("%d ", a.arr[i]);
//         i++;
//     }
//     printf("\n");

//     return 0;
// }


// Helper function to print a stack
void print_stack(const char *name, t_stack *stack) {
    printf("%s: ", name);
    for (int i = 0; i < stack->size; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    t_stack stack_a;
    t_stack stack_b;
    
    // Parse arguments to initialize stack_a
    if (parse_arguments(argc, argv, &stack_a) == -1) {
        printf(R_MSG);
        return 1;
    }

    // Initialize stack_b as empty
    stack_b.size = 0;

    printf("Initial stacks:\n");
    print_stack("Stack A", &stack_a);
    print_stack("Stack B", &stack_b);

    // Perform radix sort
    printf("\nPerforming Radix Sort:\n");
    radix_sort(&stack_a, &stack_b);

    // Print final result
    printf("\nSorted stack:\n");
    print_stack("Stack A", &stack_a);
    printf("Stack B: (should be empty)\n");
    print_stack("Stack B", &stack_b);

    // Print operation count
    printf("\nTotal operations: %d\n", operation_count);
    return 0;
}

