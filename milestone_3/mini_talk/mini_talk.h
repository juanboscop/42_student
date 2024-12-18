/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:05:58 by bosco             #+#    #+#             */
/*   Updated: 2024/12/18 13:41:17 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H


# define _POSIX_C_SOURCE 199309L
# define _XOPEN_SOURCE 500
# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define R_MSG "\033[1;31mERROR\033[0m"

extern int      g_ack_received;

typedef struct s_state
{
	pid_t           client_pid;
	int             pid_received;
	char            pid_buffer[20];
	int             pid_index;
	unsigned char   current_char;
	int             bit_count;
} t_state;

void	send_itoa(pid_t server_pid, pid_t client_pid);
void	handler_function(int signum);
void	send_char(pid_t server_pid, unsigned char c);
char	*ft_itoa(int nbr, int len);
int		num_strlen(int num);

#endif