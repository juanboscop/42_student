/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:34:18 by bosco             #+#    #+#             */
/*   Updated: 2025/01/08 20:23:58 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"
#include <time.h>


void	exit_function(pid_t server_pid)
{
	printf("%s = error sending message to the PID = %i\n", R_MSG, server_pid);
	exit(1);
}

void	send_char(pid_t server_pid, unsigned char c)
{
	int	bit;
	int	bit_val;

	bit = 7;
	while (bit >= 0)
	{
		bit_val = (c >> bit) & 1;
		if (bit_val == 0)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				exit_function(server_pid);
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				exit_function(server_pid);
		}
		bit--;
		usleep(550);
	}
}


int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	if (argc != 3)
		return (printf("%s = $FILE <PID> 'message'\n", R_MSG));
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid <= 0)
	{
		printf("%s = invalid PID\n", R_MSG);
		return (0);
	}
	i = 0;
	while (argv[2][i] != '\0')
	{
		send_char(pid, (unsigned char)argv[2][i]);
		i++;
	}
	send_char(pid, '\0');
	return (0);
}
