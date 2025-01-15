/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:01:50 by bosco             #+#    #+#             */
/*   Updated: 2024/11/26 17:41:43 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 10)
		ft_putnbr_unsigned_fd(n / 10, fd);

	c = n % 10 + '0';
	count += write(fd, &c, 1);
	if (n < 10)
		return (count);
}
