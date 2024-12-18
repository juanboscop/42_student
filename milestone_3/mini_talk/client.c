/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:34:18 by bosco             #+#    #+#             */
/*   Updated: 2024/12/18 13:54:16 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int g_ack_received = 0;

void	ack_handler(int signum)
{
	(void)signum;
	g_ack_received = 1;
}

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
		// usleep(300);
		// g_ack_received = 0;
		// while (!g_ack_received)
		// 	pause();
	}
}


int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	if (argc != 3)
	{
		printf("%s = you must put the PID and a message as argument\n", R_MSG);
		return (0);
	}
	pid = (pid_t)atoi(argv[1]);
	if (pid <= 0)
	{
		printf("%s = invalid PID\n", R_MSG);
		return (0);
	}
	signal(SIGUSR1, ack_handler);
	i = 0;
	send_itoa(pid, getpid());
	while (argv[2][i] != '\0')
	{
		send_char(pid, (unsigned char)argv[2][i]);
		i++;
	}
	send_char(pid, '\0');
	return (0);
}
