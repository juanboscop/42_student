/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 03:18:22 by bosco             #+#    #+#             */
/*   Updated: 2025/05/03 19:29:20 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// init.c
#include "philo.h"
#include "ft_printf.h"

void	initialize_philo_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal_time = data->start_time;
		data->philos[i].data = data;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->philo_count];
		i++;
	}
}

int	init_simulation(t_data *data)
{
	int				i;
	struct timeval	tv;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
		return (ft_printf("Error: memory allocation failed\n"), 1);
	data->philos = malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philos)
	{
		free(data->forks);
		return (ft_printf("Error: malloc philos failed\n"), 1);
	}
	i = 0;
	while (i < data->philo_count)
		pthread_mutex_init(&data->forks[i++], NULL);
	pthread_mutex_init(&data->print_lock, NULL);
	pthread_mutex_init(&data->state_lock, NULL);
	data->someone_died = 0;
	data->finished_eating = 0;
	gettimeofday(&tv, NULL);
	data->start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	initialize_philo_data(data);
	return (0);
}
