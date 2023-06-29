/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:12 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/29 08:59:34 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	death_loop(t_data *data);
void	creat_threads(t_data *data);
void	join_threads(t_data *data);
void	detach_threads(t_data *data);
int		inner_death_loop(t_data *data);

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = get_data();
	if (!data)
		return (1);
	if (philo_init(data, argc, argv))
		return (1);

	creat_threads(data);
	death_loop(data);
	join_threads(data);
	free_tdata(data);
	return (0);
}

void	creat_threads(t_data *data)
{
	t_philo		*philo;
	pthread_t	*thread;
	int			count;
	int			i;

	i = 0;
	count = data->philo_count;
	get_start_us();
	if (count == 1)
	{
		philo = &data->philosophers[0];
		thread = &philo->thread;
		pthread_create(thread, NULL, lonely_philo, philo);
	}
	else while (i < count)
	{
		philo = &data->philosophers[i];
		thread = &philo->thread;
		philo->last_meal_us = get_curr_us();
		pthread_create(thread, NULL, philo_routine, philo);
		i++;
	}
}

void	join_threads(t_data *data)
{
	t_philo		*philo;
	pthread_t	*thread;
	int			count;
	int			i;

	i = 0;
	count = data->philo_count;

	while (i < count)
	{
		philo = &data->philosophers[i];
		thread = &philo->thread;
		pthread_join(*thread, NULL);
		i++;
		// printf("Philo %d joined, finished_eatin -> %d\n", i, philo->is_full);
	}
}

void	detach_threads(t_data *data)
{
	t_philo		*philo;
	pthread_t	*thread;
	int			count;
	int			i;

	i = 0;
	count = data->philo_count;
	while (i < count)
	{
		philo = &data->philosophers[i];
		thread = &philo->thread;
		pthread_detach(*thread);
		i++;
	}
}

int	inner_death_loop(t_data *data)
{
	int		i;
	int		philo_count;
	t_philo	*philosophers;

	philo_count = data->philo_count;
	philosophers = data->philosophers;
	i = 0;
	while (i < philo_count)
	{
		if (is_dead(&philosophers[i], data))
		{
			return (1);
		}
		if (check_finished_eating(data))
			return (1);
		i++;
	}
	return (0);
}
