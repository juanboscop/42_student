/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:07:08 by bosco             #+#    #+#             */
/*   Updated: 2024/11/26 17:42:17 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar_fd(char c, int fd)
{
	int	count;

	count = 0;
	count += write(fd, &c, 1);
	return (count);
}
