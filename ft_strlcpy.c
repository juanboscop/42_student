/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 23:42:13 by jpavia            #+#    #+#             */
/*   Updated: 2024/09/19 17:12:00 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>


size_t ft_strlen(const char  *c);
size_t ft_strlcpy(char *destination, const char *source, size_t size);

size_t ft_strlcpy(char *destination, const char *source, size_t size)
{
    size_t i = 0;
    size_t src_len = ft_strlen(source);

    if (size == 0)  // If size is 0, just return the length of the source
        return src_len;

    // Copy until the end of source or until (size - 1) to leave space for null terminator
    while (source[i] != '\0' && i < (size - 1))
    {
        destination[i] = source[i];
        i++;
    }

    destination[i] = '\0';  // Null-terminate the destination

    return src_len;  // Return the full length of source
}

size_t ft_strlen(const char *c)
{
    size_t i = 0;
    while (c[i] != '\0')
    {
        i++;
    }
    return i;
}


// int main()
// {
//     // Test Case 1: Truncation
//     char destination1[4]; // Only enough space for 3 characters + 1 null terminator
//     size_t result1 = ft_strlcpy(destination1, "bread", sizeof(destination1));
//     printf("Test 1 - Truncation: copied string: '%s', length of source: %zu, return value: %zu\n", destination1, ft_strlen(destination1), result1);

//     // Test Case 2: No Truncation
//     char destination2[10]; // Enough space for the entire string + null terminator
//     size_t result2 = ft_strlcpy(destination2, "bread", sizeof(destination2));
//     printf("Test 2 - No Truncation: copied string: '%s', length of source: %zu, return value: %zu\n", destination2, ft_strlen(destination2), result2);

//     // Test Case 3: Empty string
//     char destination3[10]; 
//     size_t result3 = ft_strlcpy(destination3, "", sizeof(destination3));
//     printf("Test 3 - Empty string: copied string: '%s', length of source: %zu, return value: %zu\n", destination3, ft_strlen(destination3), result3);

//     // Test Case 4: Zero size buffer
//     char destination4[5]; // Test for 0-sized destination buffer
//     size_t result4 = ft_strlcpy(destination4, "test", 0);
//     printf("Test 4 - Zero size buffer: copied string: '%s', length of source: %zu, return value: %zu\n", destination4, ft_strlen(destination4), result4);

//     // Test Case 5: Exact buffer size
//     char destination5[6]; // Buffer size is exactly equal to the length of the source + null terminator
//     size_t result5 = ft_strlcpy(destination5, "bread", sizeof(destination5));
//     printf("Test 5 - Exact buffer size: copied string: '%s', length of source: %zu, return value: %zu\n", destination5, ft_strlen(destination5), result5);

// //     return 0;
// // }