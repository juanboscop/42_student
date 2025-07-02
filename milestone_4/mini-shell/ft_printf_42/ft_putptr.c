/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpavia <jpavia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:19:07 by bosco             #+#    #+#             */
/*   Updated: 2024/10/30 21:26:08 by jpavia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	address;
	int				count;

	count = 0;
	address = (unsigned long)ptr;
	if (ptr == NULL)
		count += ft_putstr_fd("(nil)", 1);
	else
	{
		ft_putstr_fd("0x", 1);
		count += 2;
		count += ft_puthex_lower_long(address);
	}
	return (count);
}
