/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:12:32 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/23 11:02:16 by kmehour          ###   ########.fr       */
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

int	is_dead(t_philo philo, t_data *data)
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
		return (1);
	}
	return (0);
}

void	lock_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_log(philo->id, LOG_FORK);
	pthread_mutex_lock(philo->right_fork);
	print_log(philo->id, LOG_FORK);
}

void	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

// int	check_philos_death(t_data *data)
// {
// 	pthread_mutex_lock(&data->write_mutex);
// 	if (data->death)
// 	{
// 		pthread_mutex_unlock(&data->write_mutex);
// 		return (1);
// 	}
// 	pthread_mutex_unlock(&data->write_mutex);
// 	return (0);
// }
