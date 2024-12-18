/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:31:15 by bosco             #+#    #+#             */
/*   Updated: 2024/12/18 14:07:00 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"


t_state g_state = {0};
// This is our one global variable holding all necessary state information.

static void handle_pid_char(t_state *st, unsigned char c)
{
	if (c == ':')
	{
		// End of PID string
		st->pid_buffer[st->pid_index] = '\0';
		st->client_pid = (pid_t)atoi(st->pid_buffer);
		st->pid_received = 1;
	}
	else
	{
		// Accumulate PID digits
		st->pid_buffer[st->pid_index++] = (char)c;
	}
}

static void handle_message_char(t_state *st, unsigned char c)
{
	if (c == '\0')
	{
		// End of message
		write(1, "\n", 1);
		// Reset for next client
		st->client_pid = 0;
		st->pid_received = 0;
		st->pid_index = 0;
	}
	else
	{
		// Print the message character
		write(1, &c, 1);
	}
}

void handler_function(int signum)
{
	g_state.current_char <<= 1;
	if (signum == SIGUSR2)
		g_state.current_char |= 1;
	g_state.bit_count++;

	if (g_state.bit_count == 8)
	{
		if (g_state.pid_received == 0)
			handle_pid_char(&g_state, g_state.current_char);
		else
			handle_message_char(&g_state, g_state.current_char);

		g_state.bit_count = 0;
		g_state.current_char = 0;

		printf("\nCLIENR PID = %d\n", g_state.client_pid);
		// Send acknowledgment if PID is known
		if (g_state.pid_received && g_state.client_pid > 0)
			kill(g_state.client_pid, SIGUSR1);
	}
}

int main(void)
{
	struct sigaction	sa;
	pid_t				pid;

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
