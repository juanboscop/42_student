/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:22:26 by bosco             #+#    #+#             */
/*   Updated: 2024/09/19 14:47:20 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *memcpy(void *dest, const void *src, size_t n);

void *memcpy(void *dest, const void *src, size_t n)
{  
    char *destination;
    const char *source;
    int i;

    destination =(char *)dest;
    source = (const char *)src;
    
    i = 0;
    while(i < n)
    {
        destination[i] = source[i];
        i++;
    }
    return dest;
}
