/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:12:32 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/29 10:46:16 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	all_finished_eating(t_data *data)
{

	pthread_mutex_lock(&data->status_mutex);
	if (data->finished_eating >= (int)data->philo_count)
	{
		pthread_mutex_unlock(&data->status_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->status_mutex);
	return (0);
}

int	is_dead(t_philo *philo, t_data *data)
{
	long int		time_to_die;
	long int		last_meal_us;

	pthread_mutex_lock(&data->status_mutex);
	last_meal_us = philo->last_meal_us;
	pthread_mutex_unlock(&data->status_mutex);
	time_to_die = data->time_to.die;
	if (delta_ms(last_meal_us, get_curr_us()) >= time_to_die)
	{
		pthread_mutex_lock(&data->write_mutex);
		if (data->death == 0)
		{
			data->death = 1;
			printf("%li %d died\n",
				get_ms_runtime(), philo->id);
			pthread_mutex_unlock(&data->write_mutex);
		}
		pthread_mutex_unlock(&data->write_mutex);
		return (1);
	}
	return (0);
}

int is_full(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->status_mutex);
	if(philo->is_full)
	{
		pthread_mutex_unlock(&data->status_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->status_mutex);
	return (0);
}

void	lock_forks(t_philo *philo)
{
		pthread_mutex_lock(philo->right_fork);
		print_log(philo->id, LOG_FORK);
		pthread_mutex_lock(philo->left_fork);
		print_log(philo->id, LOG_FORK);
}

void	unlock_forks(t_philo *philo)
{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
}

void	death_loop(t_data *data)
{
	int	stop_flag;

	stop_flag = 0;
	while (stop_flag == 0)
	{
		usleep(3000);
		stop_flag = inner_death_loop(data);

	}
}

int check_death(t_data *data)
{
	pthread_mutex_lock(&data->write_mutex);
	if(data->death)
	{
		pthread_mutex_unlock(&data->write_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->write_mutex);
	return (0);
}
