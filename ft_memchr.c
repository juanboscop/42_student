/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:12:06 by bosco             #+#    #+#             */
/*   Updated: 2024/09/19 16:27:14 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *memchr(const void *s, int c, size_t n);

void *memchr(const void *s, int c, size_t n)
{
    unsigned char find_word;
    int i;
    const unsigned char *ptr;

    ptr = (const unsigned char *)s;
    find_word = (unsigned char)c;
    i = 0;
    while(i < n)
    {
        if(ptr[i] == find_word)
            return (void *)(ptr + i);

        i++;
    }
    return NULL;
}
