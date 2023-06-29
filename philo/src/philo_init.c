/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:29 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/29 08:57:15 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philosophers(t_data *data);
void	init_fork_mutex(t_data *data);
void	swap_forks(t_philo *philo);

t_data	*get_data(void)
{
	static t_data	*data = NULL;

	if (!data)
		data = malloc(sizeof(t_data));
	return (data);
}

int	philo_init(t_data *data, int argc, char *argv[])
{
	data->meal_count = -1;
	data->death = 0;
	data->finished_eating = 0;
	if (parse_arguments(argc, argv, data))
	{
		free(data);
		return (1);
	}
	init_fork_mutex(data);
	init_philosophers(data);
	return (0);
}

void	init_philosophers(t_data *data)
{
	int	philo_count;
	int	i;

	philo_count = data->philo_count;
	data->philosophers = malloc(sizeof(t_philo) * philo_count);
	i = 0;
	while (i < philo_count)
	{
		data->philosophers[i].id = i + 1;
		data->philosophers[i].left_fork = &data->fork_mutex[i];
		data->philosophers[i].right_fork = &data->fork_mutex[(i + 1)
			% philo_count];
		if(i % 2 == 1)
			swap_forks(&data->philosophers[i]);
		// data->philosophers[i].last_meal_us = get_start_us();
		data->philosophers[i].is_full = 0;

		i++;
	}
}

void	init_fork_mutex(t_data *data)
{
	int	philo_count;
	int	i;

	philo_count = data->philo_count;
	data->fork_mutex = malloc(sizeof(pthread_mutex_t) * philo_count);
	i = 0;
	while (i < philo_count)
	{
		pthread_mutex_init(&(data->fork_mutex[i]), NULL);
		i++;
	}
	pthread_mutex_init(&data->write_mutex, NULL);
	pthread_mutex_init(&data->status_mutex, NULL);
}

void	swap_forks(t_philo *philo)
{
	pthread_mutex_t *tmp;

	tmp = philo->right_fork;
	philo->right_fork = philo->left_fork;
	philo->left_fork = tmp;
}