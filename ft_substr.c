/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:15:29 by bosco             #+#    #+#             */
/*   Updated: 2024/09/22 16:13:42 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_substr(char const *s, unsigned int start, size_t len);

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t  len_string;
    char *substring;
    int i;
    char *empty_str;
    
    if(s == NULL)
        return NULL;
    len_string = ft_strlen(s);
    if (start >= len_string)
    {
        empty_str = (char *)malloc(1);
        if (empty_str)
            empty_str[0] = '\0';
        return empty_str;
    }
    if(len > (len_string - start))
        len = len_string - start;
    substring = (char *)malloc((len + 1) * sizeof(char));
    i = 0;
    while(i < len)
    {
        substring[i] = s[start + i];
        i++;
    }
    substring[i] = '\0';
    return substring;
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
