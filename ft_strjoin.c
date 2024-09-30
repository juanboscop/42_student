/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:16:12 by bosco             #+#    #+#             */
/*   Updated: 2024/09/22 17:52:15 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t  ft_strlen(char const *c);

char *ft_strjoin(char const *s1, char const *s2)
{
    char    *join_string;
    size_t  len1;
    size_t  len2;
    size_t  i;

    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    join_string = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    if(join_string == NULL)
        return NULL;
    i = 0;
    while(i < len1)
    {
        join_string[i] = s1[i];
        i++;
    }
    while(*s2 != '\0')
    {
        join_string[i] = *s2;
        i++;
        s2++;
    }
    join_string[i] = '\0';
    return join_string;
}



size_t  ft_strlen(char const  *c)
{
    size_t  i;
    
    i = 0;
    while(c[i] != '\0')
    {
        i++;
    }
    return i;
}

// int main() {
//     char *result1 = "HelloMarikon";
//     char *result2 = "woradsdsa";

//     char *result = ft_strjoin(result1, result2);

//     // Print the result if allocation was successful
//     if (result != NULL) {
//         printf("The result is: %s\n", result);
//         free(result);  // Free the allocated memory after use
//     } else {
//         printf("Memory allocation failed!\n");
//     }

//     return 0;
// }