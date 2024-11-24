/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:33:40 by bosco             #+#    #+#             */
/*   Updated: 2024/10/28 17:08:02 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void	ft_puthex_lower(unsigned long num)
{
	char			*hex_lower;
	unsigned long	temp_quotient;
	unsigned long	temp_remainder;

	hex_lower = "0123456789abcdef";
	temp_quotient = num / 16;
	temp_remainder = num % 16;	
	if (temp_quotient != 0)
		ft_puthex_lower(temp_quotient);
	ft_putchar_fd(hex_lower[temp_remainder], 1);
}