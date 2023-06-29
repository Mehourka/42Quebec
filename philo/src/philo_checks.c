/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:12:32 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/29 08:51:45 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_finished_eating(t_data *data)
{
	int	bool;

	bool = 0;
	pthread_mutex_lock(&data->status_mutex);
	if (data->finished_eating >= (int)data->philo_count)
		bool ++;
	pthread_mutex_unlock(&data->status_mutex);
	return (bool);
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
		if (!data->death++)
			printf("%li %d died\n",
				get_ms_runtime(), philo->id);
		pthread_mutex_unlock(&data->write_mutex);
		return (1);
	}
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
		usleep(5000);
		stop_flag = inner_death_loop(data);
	}
}

int check_no_dead(t_data *data)
{
	pthread_mutex_lock(&data->write_mutex);
	if(data->death)
	{
		pthread_mutex_unlock(&data->write_mutex);
		return (FALSE);
	}
	pthread_mutex_unlock(&data->write_mutex);
	return (TRUE);
}
