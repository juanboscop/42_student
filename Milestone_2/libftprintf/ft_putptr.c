/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:19:07 by bosco             #+#    #+#             */
/*   Updated: 2024/11/26 17:41:14 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	address;
	int				count;

	address = (unsigned long)ptr;
	count = 0;
	count += ft_putstr_fd("0x", 1);
	if (!address)
		count += ft_putstr_fd("nul", 1);
	if (address == 0)
		count += ft_putchar_fd('0', 1);
	else
		count += ft_puthex_lower(address);
	return (count);
}
