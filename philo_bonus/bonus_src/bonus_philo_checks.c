/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philo_checks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:04:11 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/29 11:49:04 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

int	is_dead(t_philo *philo)
{
	long int	last_meal;
	t_data		*data;

	data = philo->data;
	last_meal = philo->last_meal_us;
	if (delta_ms(last_meal, get_curr_us()) >= data->time_to_die)
	{
		sem_wait(philo->data->write_sem);
		printf("%li %d died\n", get_ms_runtime(), philo->id);
		free_tdata(data);
		exit(1);
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
