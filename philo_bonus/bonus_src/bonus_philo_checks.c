/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philo_checks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:04:11 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/23 12:07:01 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

int	is_dead(t_philo *philo)
{
	struct timeval	last_meal;
	struct timeval	curr_time;
	t_data			*data;

	data = philo->data;
	last_meal = philo->last_meal_tv;
	gettimeofday(&curr_time, NULL);
	if (delta_ms(last_meal, curr_time) >= data->time_to_die)
	{
		sem_wait(philo->data->write_sem);
		printf("%li %d died\n", get_ms_runtime(), philo->id);
		free_tdata(data);
		exit (1);
	}
	return (0);
}

void	*check_self(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (1)
	{
		usleep(3000);
		is_dead(philo);
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
