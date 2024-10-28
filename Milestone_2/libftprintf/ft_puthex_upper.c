/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:33:20 by bosco             #+#    #+#             */
/*   Updated: 2024/10/28 16:52:02 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void	ft_puthex_upper(unsigned int num)
{
	char			*hex_upper;
	unsigned int	temp_quotient;
	unsigned int	temp_remainder;

	hex_upper = "0123456789ABCDEF";
	temp_quotient = num / 16;
	temp_remainder = num % 16;	
	if (temp_quotient != 0)
		ft_puthex_upper(temp_quotient);
	ft_putchar_fd(hex_upper[temp_remainder], 1);
}
