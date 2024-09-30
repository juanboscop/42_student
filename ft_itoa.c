/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:40:44 by bosco             #+#    #+#             */
/*   Updated: 2024/09/30 12:05:31 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int count_digits(int n)
{
    int count;
    count = 0;
    if (n <= 0)
        count = 1;
    while (n != 0)
    {
        n = n / 10;
        count++;
    }
    return count;
}

char *ft_itoa(int n)
{
    char *number;
    int digits;
    int is_negative;

    if (n == -2147483648)
        return (ft_strdup("-2147483648"));

    digits = count_digits(n);
    is_negative = (n < 0);
    number = (char *)malloc((digits + 1) * sizeof(char));
    if (!number)
        return NULL;
    number[digits] = '\0';
    if (is_negative)
        n = -n;
    while (digits-- > 0)
    {
        number[digits] = (n % 10) + '0';
        n = n / 10;
        if (digits == 0 && is_negative)
            number[digits] = '-';
    }
    return number;
}
