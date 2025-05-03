/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:07:16 by bosco             #+#    #+#             */
/*   Updated: 2025/05/03 19:32:51 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count && data->philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	if (data->forks)
	{
		i = 0;
		while (i < data->philo_count)
			pthread_mutex_destroy(&data->forks[i++]);
		free(data->forks);
		data->forks = NULL;
	}
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->state_lock);
	if (data->philos)
	{
		free(data->philos);
		data->philos = NULL;
	}
}
