/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lower_long.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpavia <jpavia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:12:07 by jpavia            #+#    #+#             */
/*   Updated: 2024/10/30 21:17:07 by jpavia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_puthex_lower_long(unsigned long num)
{
	char			*hex_lower;
	unsigned long	temp_quotient;
	unsigned long	temp_remainder;
	int				count;

	count = 0;
	hex_lower = "0123456789abcdef";
	temp_quotient = num / 16;
	temp_remainder = num % 16;
	if (temp_quotient != 0)
		count += ft_puthex_lower_long(temp_quotient);
	count += ft_putchar_fd(hex_lower[temp_remainder], 1);
	return (count);
}
