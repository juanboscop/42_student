/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 03:45:59 by bosco             #+#    #+#             */
/*   Updated: 2025/05/03 18:27:31 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "ft_printf.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// A simple function to convert a long integer to a string (base 10).
// It assumes the buffer is large enough.
void	ft_long_to_str(long n, char *buffer)
{
	int		len;
	long	temp;

	len = 0;
	if (n == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return ;
	}
	temp = n;
	while (temp != 0)
	{
		len++;
		temp = temp / 10;
	}
	buffer[len] = '\0';
	while (n)
	{
		buffer[--len] = '0' + (n % 10);
		n = n / 10;
	}
}

// Formats a timestamp (in milliseconds) to a string.
// It simply converts the ms value into a string.
void	format_timestamp(long timestamp, char *buffer, int buf_size)
{
	(void)buf_size;
	ft_long_to_str(timestamp, buffer);
}

// The message format is: [<ms> ms] Philosopher <id> <action>
void	print_log(t_data *data, int id, const char *action, const char *color)
{
	char	timestamp[16];
	long	now;

	pthread_mutex_lock(&data->print_lock);
	pthread_mutex_lock(&data->state_lock);
	if (!data->someone_died || ft_strcmp(action, "died") == 0)
	{
		now = current_timestamp_ms() - data->start_time;
		format_timestamp(now, timestamp, sizeof(timestamp));
		ft_printf("%s%s %d %s\n", color, timestamp, id, action);
	}
	pthread_mutex_unlock(&data->state_lock);
	pthread_mutex_unlock(&data->print_lock);
}

// Sleeps for 'ms' milliseconds while checking if someone has died.
// This sleep is broken into 1 ms intervals.
void	sleep_ms(long ms, t_data *data)
{
	long	start;

	start = current_timestamp_ms();
	while (1)
	{
		pthread_mutex_lock(&data->state_lock);
		if (data->someone_died)
		{
			pthread_mutex_unlock(&data->state_lock);
			break ;
		}
		pthread_mutex_unlock(&data->state_lock);
		if ((current_timestamp_ms() - start) >= ms)
			break ;
		usleep(1000);
	}
}
