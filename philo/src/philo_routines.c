/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:16 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/23 11:56:50 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	lock_forks(t_philo *philo);
void	unlock_forks(t_philo *philo);
void	eat_routine(t_data *data, t_philo *philo);
void	sleep_routine(t_data *data, int id);
void	think_routine(t_data *data, int id);

void	*philo_routine(void *arg)
{
	t_data	*data;
	t_philo	*philo;
	int		meal_count;

	data = get_data();
	philo = arg;
	meal_count = data->meal_count;
	if (philo->id % 2)
		micro_sleep(data->time_to.eat / 2);
	while (meal_count != 0)
	{
		lock_forks(philo);
		eat_routine(data, philo);
		meal_count--;
		unlock_forks(philo);
		if (meal_count == 0)
			break ;
		sleep_routine(data, philo->id);
		think_routine(data, philo->id);
	}
	pthread_mutex_lock(&data->status_mutex);
	data->finished_eating++;
	philo->is_full = 1;
	pthread_mutex_unlock(&data->status_mutex);
	return (NULL);
}

void	eat_routine(t_data *data, t_philo *philo)
{
	long int	eat_time;

	eat_time = data->time_to.eat;
	if (is_dead(*philo, data))
	{
		micro_sleep(100);
	}
	gettimeofday(&philo->last_meal_tv, NULL);
	print_log(philo->id, LOG_EAT);
	micro_sleep(eat_time);
}

void	sleep_routine(t_data *data, int id)
{
	long int	sleep_time;

	sleep_time = data->time_to.sleep;
	print_log(id, LOG_SLEEP);
	micro_sleep(sleep_time);
}

void	think_routine(t_data *data, int id)
{
	(void)data;
	print_log(id, LOG_THINK);
	usleep(50);
}
