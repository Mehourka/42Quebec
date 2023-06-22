/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philo_checks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:04:11 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/22 15:08:28 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

int	is_dead(t_philo *philo)
{
	long int		time_to_die;
	struct timeval	last_meal;
	struct timeval	curr_time;
	t_data			*data;

	data = philo->data;
	time_to_die = data->time_to.die;
	last_meal = philo->last_meal_tv;
	gettimeofday(&curr_time, NULL);
	if (delta_ms(last_meal, curr_time) > (int)time_to_die)
	{
		return (1);
	}
	return (0);
}

void	*check_self(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (1)
	{
		usleep(1000);
		if (is_dead(philo))
		{
			sem_wait(philo->data->write_sem);
			sem_post(philo->data->state_sem);
			printf("%li ms %d has died\n", get_ms_runtime(), philo->id);
		}
	}
	return (NULL);
}

void	lock_forks(sem_t *sema_forks, int id)
{
	sem_wait(sema_forks);
	print_log(id, LOG_FORK);
	sem_wait(sema_forks);
	print_log(id, LOG_FORK);
}

void	unlock_forks(sem_t *sema_forks)
{
	sem_post(sema_forks);
	sem_post(sema_forks);
}
