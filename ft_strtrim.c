/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:59:29 by bosco             #+#    #+#             */
/*   Updated: 2024/09/23 12:26:21 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

cint is_in_set(char c, const char *set)
{
    while (*set)
    {
        if (c == *set)
            return 1;
        set++;
    }
    return 0;
}
char *ft_strtrim(char const *s1, char const *set)
{
    size_t start;
    size_t end;
    size_t i;
    char *new_string;

    if (s1 == NULL || set == NULL)
        return NULL;
    start = 0;
    while (s1[start] && is_in_set(s1[start], set))
        start++;
    end = 0;
    while (s1[end])
        end++;
    end--;
    while (end > start && is_in_set(s1[end], set))
        end--;
    new_string = (char *)malloc((end - start + 2) * sizeof(char));
    if (!new_string)
        return NULL;
    i = 0;
    while (start <= end)
    {
        new_string[i] = s1[start];
        i++;
        start++;
    }
    new_string[i] = '\0';
    return new_string;
}
