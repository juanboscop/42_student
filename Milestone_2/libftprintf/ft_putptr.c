/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:19:07 by bosco             #+#    #+#             */
/*   Updated: 2024/10/28 16:52:36 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void    ft_putptr(void *ptr)
{
	unsigned long address;

	address  = (unsigned long)ptr;

	ft_putstr_fd("0x", 1);
	if (address == 0)
		ft_putchar_fd('0', 1);
	else
		ft_puthex_lower(address);
}
