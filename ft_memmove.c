/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:10:53 by bosco             #+#    #+#             */
/*   Updated: 2024/09/19 16:11:07 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *memmove(void *dest, const void *src, size_t n);

void *memmove(void *dest, const void *src, size_t n)
{
    char *destination;
    const char *source;
    size_t remaining;

    remaining = n;
    if (source < destination && destination < source + n)
    {
        destination += n; // Move to the end of the destination
        source += n;      // Move to the end of the source
        while (remaining > 0) 
        {
            *(--destination) = *(--source); // Copy byte by byte
            remaining--;
        }
    }
    else
    {
        while(remaining > 0){
            *destination++ = *source++; // Copy byte by byte
            remaining--;
        }
    }
    return dest; // Return the original destination pointer
}
