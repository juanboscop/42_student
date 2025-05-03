/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 03:44:16 by bosco             #+#    #+#             */
/*   Updated: 2025/05/02 23:58:21 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include "ft_printf.h"

int	philo_died(t_philo *philo, t_data *data)
{
	long	now;
	int		result;

	pthread_mutex_lock(&data->state_lock);
	now = current_timestamp_ms();
	result = (now - philo->last_meal_time >= data->time_to_die
			&& (!data->meals_required
				|| philo->meals_eaten < data->meals_required));
	pthread_mutex_unlock(&data->state_lock);
	return (result);
}

int	check_philosopher_death(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_count)
	{
		if (philo_died(&data->philos[i], data))
		{
			pthread_mutex_lock(&data->state_lock);
			if (!data->someone_died)
			{
				data->someone_died = 1;
				pthread_mutex_unlock(&data->state_lock);
				print_log(data, data->philos[i].id, "died", RED);
				return (1);
			}
			pthread_mutex_unlock(&data->state_lock);
		}
	}
	return (0);
}

int	check_all_finished(t_data *data)
{
	int	result;

	pthread_mutex_lock(&data->state_lock);
	result = (data->meals_required
			&& data->finished_eating >= data->philo_count);
	pthread_mutex_unlock(&data->state_lock);
	return (result);
}

void	*monitor_thread(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		if (check_philosopher_death(data))
			break ;
		if (check_all_finished(data))
			break ;
		usleep(1000);
	}
	return (NULL);
}
