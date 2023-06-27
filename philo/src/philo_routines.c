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
	if (philo->id % 2 == 0)
		micro_sleep(data->time_to.eat / 2);
	while (check_no_dead(data) && meal_count != 0)
	{
		eat_routine(data, philo);
		meal_count--;
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

void	*lonely_philo(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	data = get_data();
	philo = arg;
	pthread_mutex_lock(philo->right_fork);
	print_log(philo->id, LOG_FORK);
	while (is_dead(philo, data) != 1)
		usleep(1000);
	pthread_mutex_unlock(philo->right_fork);
	return (NULL);
}

void	eat_routine(t_data *data, t_philo *philo)
{
	long int	eat_time;

	eat_time = data->time_to.eat;
	lock_forks(philo);
	is_dead(philo, data);
	pthread_mutex_lock(&data->status_mutex);
	gettimeofday(&philo->last_meal_tv, NULL);
	pthread_mutex_unlock(&data->status_mutex);
	print_log(philo->id, LOG_EAT);
	micro_sleep(eat_time);
	unlock_forks(philo);

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
	// usleep(5000);
}

