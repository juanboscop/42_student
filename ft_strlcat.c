/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:47:27 by bosco             #+#    #+#             */
/*   Updated: 2024/09/19 13:05:10 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


size_t strlcat(char *destination, const char *source, size_t size);
size_t ft_strlen(const char  *c);


size_t ft_strlen(const char *c)
{
    size_t i = 0;
    while (c[i] != '\0')
    {
        i++;
    }
    return i;
}
size_t strlcat(char *destination, const char *source, size_t size)
{
    size_t  destlen;
    size_t  srclen;
    int i;

    i = 0;
    destlen = ft_strlen(destination);
    srclen  = ft_strlen(source);
    if (size == 0)
        return srclen;
    if(size <= destlen)
        return size + srclen;
    while(source[i] != '\0' && (destlen + i) < (size - 1))
    {
        destination[i + destlen] = source[i];
        i++;
    }
    if ((destlen + i) < size)
        destination[destlen + i] = '\0';
    return destlen + srclen;
}
