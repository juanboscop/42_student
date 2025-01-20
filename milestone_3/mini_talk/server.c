/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpavia <jpavia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:31:15 by bosco             #+#    #+#             */
/*   Updated: 2025/01/20 15:30:45 by jpavia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"
#include "ft_printf_42/ft_printf.h"
#include "ft_printf_42/libft/libft.h"

t_server_state	g_server = {0, 0};

static void	handle_exit(int signum)
{
	(void)signum;
	write(1, "\nServer exiting cleanly.\n", 25);
	exit(0);
}

static void	handler_function(int signum, siginfo_t *info, void *context)
{
	pid_t	client_pid;

	(void)context;
	client_pid = info->si_pid;
	g_server.current_char <<= 1;
	if (signum == SIGUSR2)
		g_server.current_char |= 1;
	g_server.bit_count++;
	if (g_server.bit_count == 8)
	{
		if (g_server.current_char == '\0')
			write(1, "\n", 1);
		else
			write(1, &g_server.current_char, 1);
		g_server.bit_count = 0;
		g_server.current_char = 0;
	}
	if (kill(client_pid, SIGUSR1) == -1)
		write(1, "Error sending ACK\n", 18);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	signal(SIGINT, handle_exit);
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler_function;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
