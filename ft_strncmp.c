/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:51:00 by bosco             #+#    #+#             */
/*   Updated: 2024/09/19 17:11:55 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int strncmp(const char *s1, const char *s2, size_t n);

int strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    while(i < n && (s1[i] != '\0' || s2[i] != '\0'))
    {
        if((unsigned char)s1[i] != (unsigned char)s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        i++;
    }
    return 0;
}