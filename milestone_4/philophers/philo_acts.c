/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_acts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:49:03 by bosco             #+#    #+#             */
/*   Updated: 2025/05/03 14:04:02 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	current_timestamp_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	philo_eat(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->left_fork);
	print_log(data, philo->id, "has taken a fork", CYAN);
	pthread_mutex_lock(philo->right_fork);
	print_log(data, philo->id, "has taken a fork", CYAN);
	pthread_mutex_lock(&data->state_lock);
	philo->last_meal_time = current_timestamp_ms();
	philo->meals_eaten++;
	if (data->meals_required && philo->meals_eaten == data->meals_required)
		data->finished_eating++;
	pthread_mutex_unlock(&data->state_lock);
	print_log(data, philo->id, "is eating", GREEN);
	responsive_sleep(data->time_to_eat, data);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	philo_sleep(t_philo *philo, t_data *data)
{
	print_log(data, philo->id, "is sleeping", BLUE);
	responsive_sleep(data->time_to_sleep, data);
}

void	philo_think(t_philo *philo, t_data *data)
{
	print_log(data, philo->id, "is thinking", YELLOW);
}

void	*philo_thread(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (data->philo_count == 1)
	{
		handle_single_philo(philo, data);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(1000);
	while (simulation_should_continue(data, philo))
	{
		philo_eat(philo, data);
		if (!simulation_should_continue(data, philo))
			break ;
		philo_sleep(philo, data);
		if (!simulation_should_continue(data, philo))
			break ;
		philo_think(philo, data);
	}
	return (NULL);
}
