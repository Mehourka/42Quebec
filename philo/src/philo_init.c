/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:29 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/16 16:30:30 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philosophers(t_data *data);
void	init_philo_times(t_data *data);
void	init_fork_mutex(t_data *data);

t_data *philo_init(void)
{
	static t_data *data = NULL;

	if (!data)
	{
		// Init start runtime
		get_ms_runtime();

		// Init data structure
		data = malloc(sizeof(t_data));
		data->philo_count = PHILO_COUNT;
		init_fork_mutex(data);
		init_philosophers(data);
		init_philo_times(data);
	}
	return (data);
}

void	init_philosophers(t_data *data)
{
	int				philo_count;
	int				i;
	// t_philo			*philosophers;
	// pthread_mutex_t	*forks;

	philo_count = data->philo_count;
	data->philosophers = malloc(sizeof(t_philo) * philo_count);
	// forks = data->fork_mutex;

	i = 0;
	while (i < philo_count)
	{
		data->philosophers[i].id = i;
		data->philosophers[i].left_fork = &data->fork_mutex[i];
		data->philosophers[i].right_fork = &data->fork_mutex[(i + 1) % philo_count];
		data->philosophers[i].last_meal_ms = 0;
		data->philosophers[i].meal_count = 0;
		i++;
	}
}

void	init_philo_times(t_data *data)
{
	data->time_to.die = TIMETO_DIE;
	data->time_to.eat = TIMETO_EAT;
	data->time_to.sleep = TIMETO_SLEEP;
	data->time_to.think = TIMETO_THINK;
}

void	init_fork_mutex(t_data *data)
{
	int philo_count;
	int i;

	philo_count = data->philo_count;
	data->fork_mutex = malloc(sizeof(pthread_mutex_t) * philo_count);
	i = 0;
	while(i < philo_count)
	{
		pthread_mutex_init(&(data->fork_mutex[i]), NULL);
		printf("Initializing mutex %d - %p\n", i, data->fork_mutex);
		i++;
	}

}