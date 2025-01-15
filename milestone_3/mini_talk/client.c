/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:34:18 by bosco             #+#    #+#             */
/*   Updated: 2025/01/15 12:39:10 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"
#include <time.h>

int	g_ack_received = 1;

void	ack_handler(int sig)
{
	(void)sig;
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
		usleep(1000);
	}
	while (!g_ack_received)
		;
	g_ack_received = 0;
}

int	restart_function(void)
{
	struct sigaction	act;

	memset(&act, 0, sizeof(act));
	act.sa_handler = ack_handler;
	act.sa_flags = SA_RESTART | SA_NODEFER;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, NULL) < 0)
	{
		write(2, "Error setting signal handler\n", 29);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	restart_function();
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
