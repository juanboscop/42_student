/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:05:58 by bosco             #+#    #+#             */
/*   Updated: 2025/01/08 18:43:15 by bosco            ###   ########.fr       */
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
# include <limits.h>

# define R_MSG "\033[1;31mERROR\033[0m"

void	handler_function(int signum);
void	send_char(pid_t server_pid, unsigned char c);
int		ft_atoi(const char *str);

#endif