/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:29 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/23 10:19:40 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philosophers(t_data *data);
void	init_philo_times(t_data *data);
void	init_fork_mutex(t_data *data);

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
		data->philosophers[i].id = i;
		data->philosophers[i].left_fork = &data->fork_mutex[i];
		data->philosophers[i].right_fork = &data->fork_mutex[(i + 1)
			% philo_count];
		data->philosophers[i].last_meal_tv = get_start_tv();
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
