/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 03:33:39 by bosco             #+#    #+#             */
/*   Updated: 2025/05/03 18:26:41 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// philo.h
#ifndef PHILO_H

# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// ANSI color codes for logs
# define RESET	"\033[0m"
# define RED		"\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define CYAN    "\033[36m"

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				philo_count;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				meals_required;
	int				finished_eating;
	int				someone_died;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	state_lock;
	t_philo			*philos;
}	t_data;

// Utility functions for time and logging
long	current_timestamp_ms(void);
void	format_timestamp(long timestamp, char *buffer, int buf_size);
void	print_log(t_data *data, int id, const char *action, const char *color);

// Other prototypes
int		parse_input(int argc, char **argv, t_data *data);
int		init_simulation(t_data *data);
void	*philo_thread(void *arg);
void	*monitor_thread(void *arg);
void	sleep_ms(long ms, t_data *data);
void	cleanup(t_data *data);

// philo_acts.c
long	current_timestamp_ms(void);
void	*philo_thread(void *arg);
void	philo_eat(t_philo *philo, t_data *data);
void	philo_sleep(t_philo *philo, t_data *data);
void	philo_think(t_philo *philo, t_data *data);

// philo_acts_utils.c
int		simulation_should_continue(t_data *data, t_philo *philo);
void	responsive_sleep(int ms, t_data *data);
void	handle_single_philo(t_philo *philo, t_data *data);
#endif
// Note: Valgrind may show 'possibly lost' due to pthread_detach.
// This is not a real memory leak, just thread internals.