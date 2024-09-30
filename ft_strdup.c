/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:48:14 by bosco             #+#    #+#             */
/*   Updated: 2024/09/20 11:14:39 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stddef.h>

char *ft_strdup(const char *s);
char *ft_strdup(const char *s)
{
    size_t  size;
    char    *replica;
    size_t  i;

    size = ft_strlen(s);
    replica = (char *)malloc((size + 1) * sizeof(char));
    if(replica == NULL)
        return NULL;
    
    i = 0;
    while(i < size)
    {
        replica[i] = s[i];
        i++;
    }
    replica[i] = '\0';
    return replica;
    
}
size_t  ft_strlen(char  *c)
{
    size_t  i;
    
    i = 0;
    while(c[i] != '\0')
    {
        i++;
    }
    return i;
}

