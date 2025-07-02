/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpavia <jpavia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:08:21 by bosco             #+#    #+#             */
/*   Updated: 2024/10/30 20:26:46 by jpavia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	count;

	if (!s)
		s = "(null)";
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i++], 1);
		count++;
	}
	return (count);
}
