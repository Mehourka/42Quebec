/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:16 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/19 17:47:24 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void lock_forks(t_philo *philo);
void unlock_forks(t_philo *philo);
void eat_routine(t_data *data, int id);
void sleep_routine(t_data *data, int id);
void think_routine(t_data *data, int id);

void *philo_routine(void *arg)
{
	t_data *data;
	t_philo *philo;

	
	data = get_data();
	philo = arg;
	int id = philo->id;
	while(1)
	{
		// pthread_mutex_lock(&data->write_mutex);
		// if(data->death)
		// {
		// 	pthread_mutex_unlock(&data->write_mutex);
		// 	break;
		// }
		// pthread_mutex_unlock(&data->write_mutex);
		
		lock_forks(philo);
		philo->last_meal_ms = get_ms_runtime();
		eat_routine(data, id);
		unlock_forks(philo);
		sleep_routine(data, id);
		think_routine(data, id);
	}
	printf("PHILO %d FINISHED\n", philo->id);
	return (NULL);
}

void lock_forks(t_philo *philo)
{

	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->right_fork);
		print_log(philo->id, LOG_FORK);
		pthread_mutex_lock(philo->left_fork);
		print_log(philo->id, LOG_FORK);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_log(philo->id, LOG_FORK);
		pthread_mutex_lock(philo->right_fork);
		print_log(philo->id, LOG_FORK);
	}

}

void unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void eat_routine(t_data *data, int id)
{
	long int eat_time;

	eat_time = data->time_to.eat;
	print_log(id, LOG_EAT);
	micro_sleep(eat_time);
}

void sleep_routine(t_data *data, int id)
{
	long int sleep_time;

	sleep_time = data->time_to.sleep;
	print_log(id, LOG_SLEEP);
	micro_sleep(sleep_time);

}

void think_routine(t_data *data, int id)
{
	(void) data;
	
	print_log(id, LOG_THINK);
}
