/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:08:00 by bosco             #+#    #+#             */
/*   Updated: 2024/09/19 17:11:51 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *strnstr(const char *haystack, const char *needle, size_t n)
{
    size_t i;
    size_t j;

    if (*needle == '\0')
        return (char *)haystack;

    i = 0;
    while (haystack[i] != '\0' && i < n)
    {
        j = 0;
        while (needle[j] != '\0' && haystack[i + j] != '\0' && (i + j) < n && haystack[i + j] == needle[j])
        {
            j++;
        }
        if (needle[j] == '\0')
            return (char *)&haystack[i];
        
        i++;
    }

    // If no match found, return NULL
    return NULL;
}