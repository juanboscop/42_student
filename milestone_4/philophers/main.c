/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:04:13 by bosco             #+#    #+#             */
/*   Updated: 2025/05/03 19:26:17 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "ft_printf.h"

int	start_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_create(&(data->philos[i].thread), NULL,
				philo_thread, &(data->philos[i])) != 0)
			return (ft_printf("Error: thread create failed\n"), 1);
		if (data->philo_count > 1)
			pthread_detach(data->philos[i].thread);
		i++;
	}
	return (0);
}


int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	monitor;

	ft_bzero(&data, sizeof(t_data));
	if (parse_input(argc, argv, &data))
		return (1);
	if (init_simulation(&data))
		return (1);
	if (start_philos(&data))
		return (1);
	if (pthread_create(&monitor, NULL, monitor_thread, &data) != 0)
		return (ft_printf("Error: monitor thread failed\n"), 1);
	pthread_join(monitor, NULL);
	cleanup(&data);
	return (0);
}
