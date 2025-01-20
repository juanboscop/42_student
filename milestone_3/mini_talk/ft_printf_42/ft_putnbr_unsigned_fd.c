/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpavia <jpavia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:01:50 by bosco             #+#    #+#             */
/*   Updated: 2024/10/30 19:54:36 by jpavia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
	count++;
	return (count);
}
