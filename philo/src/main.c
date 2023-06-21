/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:12 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/20 17:59:22 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	death_loop(t_data *data);
int		check_finished_eating(t_data *data, int *flag);
void	creat_threads(t_data *data);
void	join_threads(t_data *data);

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

void creat_threads(t_data *data)
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
		pthread_create(thread, NULL, philo_routine, philo);
		i++;
	}
}

void join_threads(t_data *data)
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
	}
}


void	death_loop(t_data *data)
{
	int		i;
	int		philo_count;
	t_philo	*philosophers;
	int		flag;

	flag = 0;
	philo_count = data->philo_count;
	philosophers = data->philosophers;
	while (!flag)
	{
		usleep(3000);
		i = 0;
		while (i < philo_count)
		{
			if (is_dead(philosophers[i], data, &flag))
				break ;
			if (check_finished_eating(data, &flag))
				break ;
			i++;
		}
	}
}

int	is_dead(t_philo philo, t_data *data, int *flag)
{
	long int		time_to_die;
	struct timeval	last_meal;
	struct timeval	curr_time;

	pthread_mutex_lock(&data->status_mutex);
	if (philo.is_full)
	{
		pthread_mutex_unlock(&data->status_mutex);
		return (0);
	}
	pthread_mutex_unlock(&data->status_mutex);
	time_to_die = data->time_to.die;
	last_meal = philo.last_meal_tv;
	gettimeofday(&curr_time, NULL);
	if (delta_ms(last_meal, curr_time) > time_to_die)
	{
		*flag = 1;
		pthread_mutex_lock(&data->write_mutex);
		data->death = 1;
		printf("%li ms %d has died\n", get_ms_runtime(), philo.id + 1);
		pthread_mutex_unlock(&data->write_mutex);
		return (1);
	}
	return (0);
}

int	check_finished_eating(t_data *data, int *flag)
{
	int	bool;

	bool = 0;
	pthread_mutex_lock(&data->status_mutex);
	if (data->finished_eating >= (int)data->philo_count)
	{
		bool ++;
		*flag = 1;
	}
	pthread_mutex_unlock(&data->status_mutex);
	return (bool);
}
