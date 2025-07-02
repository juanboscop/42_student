/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpavia <jpavia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:33:20 by bosco             #+#    #+#             */
/*   Updated: 2024/10/30 21:12:36 by jpavia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_puthex_upper(unsigned int num)
{
	char			*hex_upper;
	unsigned int	temp_quotient;
	unsigned int	temp_remainder;
	int				count;

	count = 0;
	hex_upper = "0123456789ABCDEF";
	temp_quotient = num / 16;
	temp_remainder = num % 16;
	if (temp_quotient != 0)
		count += ft_puthex_upper(temp_quotient);
	count += ft_putchar_fd(hex_upper[temp_remainder], 1);
	return (count);
}
