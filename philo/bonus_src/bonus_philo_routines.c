/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:16 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/20 18:23:33 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

void	lock_forks(t_philo *philo);
void	unlock_forks(t_philo *philo);
void	eat_routine(t_data *data, int id, struct timeval *last_meal_tv);
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
		pthread_mutex_lock(&data->write_mutex);
		if (data->death)
		{
			pthread_mutex_unlock(&data->write_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->write_mutex);
		lock_forks(philo);
		eat_routine(data, philo->id, &philo->last_meal_tv);
		unlock_forks(philo);
		sleep_routine(data, philo->id);
		think_routine(data, philo->id);
		meal_count--;
	}
	pthread_mutex_lock(&data->status_mutex);
	data->finished_eating++;
	philo->is_full = 1;
	pthread_mutex_unlock(&data->status_mutex);
	return (NULL);
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

void	eat_routine(t_data *data, int id, struct timeval *last_meal_tv)
{
	long int	eat_time;

	eat_time = data->time_to.eat;
	print_log(id, LOG_EAT);
	gettimeofday(last_meal_tv, NULL);
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

// void	test_routine(void *arg)
// {
// 	t_data *data;
// 	t_philo *philo;

// 	data = get_data();
// 	philo = arg;
// 	int id = philo->id;

// 	for (int i = 0; i < 5; i++)
// 	{
// 		// micro_sleep(100);
// 		eat_routine(data, id, &philo->last_meal_tv);
// 		// is_dead(*philo, data);
// 	}
// 	printf("Runtime %li", get_ms_runtime());
// }