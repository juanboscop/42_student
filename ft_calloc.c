/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:20:41 by bosco             #+#    #+#             */
/*   Updated: 2024/09/20 10:47:58 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void    *ft_calloc(size_t num, size_t size);

void    *ft_calloc(size_t num, size_t size)
{
    size_t  total_size;
    void    *ptr;
    size_t  i;
    
    if(num == 0 || size == 0)
        return malloc(0);

    total_size = num * size;
    if((total_size / num) != size)
        return NULL;
    
    ptr = malloc(total_size);
    if(ptr == NULL)
        return NULL;
    
    i = 0;
    while(i < total_size)
    {
        ((char *)ptr)[i] = 0;
        i++;
    }
    return ptr;
}
