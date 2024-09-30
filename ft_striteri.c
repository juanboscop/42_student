/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:52:57 by bosco             #+#    #+#             */
/*   Updated: 2024/09/30 11:11:11 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    unsigned int    i;
    char *result;
    
    if(!s || !f)
        return NULL;
    while(s[i] != '\0')
    {
        (*f)(i, s + i);
        i++;
    }
}