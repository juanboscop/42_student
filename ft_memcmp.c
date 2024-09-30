/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:28:37 by bosco             #+#    #+#             */
/*   Updated: 2024/09/19 16:50:36 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int memcmp(const void *s1, const void *s2, size_t n);

int memcmp(const void *s1, const void *s2, size_t n)
{
    int i;
    const unsigned char *ptr1;
    const unsigned char *ptr2;

    ptr1 = (const unsigned char *)s1;
    ptr2 = (const unsigned char *)s2;

    i = 0;
    while(i < n)
    {
        if(ptr1[i] != ptr2[i])
            return (ptr1[i] - ptr2[i]);
        
        i++;
    }
    return 0;
}
