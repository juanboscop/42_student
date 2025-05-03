/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_acts_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:56:01 by bosco             #+#    #+#             */
/*   Updated: 2025/05/03 18:35:56 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	simulation_should_continue(t_data *data, t_philo *philo)
{
	int	continue_sim;

	pthread_mutex_lock(&data->state_lock);
	continue_sim = !(data->someone_died
			|| (data->meals_required
				&& philo->meals_eaten >= data->meals_required));
	pthread_mutex_unlock(&data->state_lock);
	return (continue_sim);
}

void	responsive_sleep(int ms, t_data *data)
{
	long	start;

	start = current_timestamp_ms();
	while (current_timestamp_ms() - start < ms)
	{
		pthread_mutex_lock(&data->state_lock);
		if (data->someone_died)
		{
			pthread_mutex_unlock(&data->state_lock);
			break ;
		}
		pthread_mutex_unlock(&data->state_lock);
		usleep(1000);
	}
}

void	handle_single_philo(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->left_fork);
	print_log(data, philo->id, "has taken a fork", CYAN);
	pthread_mutex_unlock(philo->left_fork);
	responsive_sleep(data->time_to_die, data);
	pthread_mutex_lock(&data->state_lock);
	data->someone_died = 1;
	pthread_mutex_unlock(&data->state_lock);
}

