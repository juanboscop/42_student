/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 03:25:46 by bosco             #+#    #+#             */
/*   Updated: 2025/05/03 19:06:33 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// parser.c
#include "philo.h"
#include "ft_printf.h"
#include "libft.h"

static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	validate_and_set(char **argv, t_data *data, int argc)
{
	data->philo_count = ft_atoi(argv[1]);
	if (data->philo_count <= 1)
	{
		printf("0 1 is dead\n");
		return (1);
	}
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	data->meals_required = 0;
	if (argc == 6)
		data->meals_required = ft_atoi(argv[5]);
	if (data->philo_count < 1 || data->time_to_die < 1 || data->time_to_eat < 1
		|| data->time_to_sleep < 1 || (argc == 6 && data->meals_required < 1))
		return (ft_printf("Error: arguments must be positive integers\n"), 1);
	return (0);
}

int	parse_input(int argc, char **argv, t_data *data)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (ft_printf("Must be either 4 or 5 arguments\n"));
	i = 1;
	while (i < argc)
	{
		if (!is_numeric(argv[i]))
			return (ft_printf("Error %s is not valid\n", i));
		i++;
	}
	if (validate_and_set(argv, data, argc))
		return (1);
	return (0);
}
