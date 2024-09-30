/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:36:10 by bosco             #+#    #+#             */
/*   Updated: 2024/09/30 10:52:00 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char            *result;
    unsigned int    i;
    
    if(!s || !f)
        return NULL;
    result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
    if(!result)
        return NULL;
    i = 0;
    while(s[i] != '\0')
    {
        result[i] = (*f)(i,s[i]);
        i++;
    }
    result[i] = '\0';
    return result;
}

