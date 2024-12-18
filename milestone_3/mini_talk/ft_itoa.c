/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:49:39 by bosco             #+#    #+#             */
/*   Updated: 2024/12/18 14:01:15 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

// char	*ft_itoa(int nbr, int len)
// {
// 	long	n_tmp;
// 	char	str[11];

// 	n_tmp = nbr;
// 	str[len] = '\0';
// 	while (n_tmp)
// 		n_tmp /= 10;
// 	while (nbr)
// 	{
// 		str[--len] = (nbr % 10) + '0';
// 		nbr /= 10;
// 	}
// 	return (str);
// }

int	num_strlen(int num)
{
	int	i;

	i = 0;
	if (num == 0)
        return 1;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

void	send_itoa(pid_t server_pid, pid_t client_pid)
{
	char c_pid[20]; // Enough space for PID as a string
	int i, len;
	int tmp = client_pid;

	// Convert PID to string (manually, no sprintf)
	len = num_strlen(tmp);
	c_pid[len] = '\0';
	while (len > 0)
	{
		len--;
		c_pid[len] = (tmp % 10) + '0';
		tmp /= 10;
	}

	// Now send each character of c_pid
	i = 0;
	while (c_pid[i] != '\0')
	{
		send_char(server_pid, (unsigned char)c_pid[i]);
		i++;
	}
	// Send a delimiter to mark the end of the PID string
	// Choose ':' as a delimiter
	send_char(server_pid, (unsigned char)':');
}
