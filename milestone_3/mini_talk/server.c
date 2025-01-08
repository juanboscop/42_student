/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:31:15 by bosco             #+#    #+#             */
/*   Updated: 2025/01/08 19:50:39 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

// instead of static variable
unsigned char	g_current_char = 0;

void	handle_exit(int signum)
{
	(void)signum;
	write(1, "\nServer exiting cleanly.\n", 25);
	exit(0);
}

void	handler_function(int signum)
{
	static int				bit_count;

	g_current_char <<= 1;
	if (signum == SIGUSR2)
		g_current_char |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (g_current_char == '\0')
		{
			write(1, "\n", 1);
		}
		else
			write(1, &g_current_char, 1);
		bit_count = 0;
		g_current_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	signal(SIGINT, handle_exit);
	pid = getpid();
	printf("Server PID: %d\n", pid);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = handler_function;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
