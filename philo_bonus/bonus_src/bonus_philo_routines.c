/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philo_routines.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:16 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/23 12:18:23 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

void	lock_forks(sem_t *sema_forks, int id);
void	unlock_forks(sem_t *sema_forks);
void	eat_routine(t_philo *philo);
void	sleep_routine(t_philo *philo);
void	think_routine(t_philo *philo);
void	*check_self(void *arg);

void	*philo_routine(void *arg)
{
	t_data		*data;
	t_philo		*philo;

	data = get_data();
	philo = arg;
	if (philo->id % 2 == 0)
		micro_sleep(data->time_to_eat / 2);
	while (data->meal_count != 0)
	{
		lock_forks(data->sema_forks, philo->id);
		is_dead(philo);
		eat_routine(philo);
		unlock_forks(data->sema_forks);
		data->meal_count--;
		if (data->meal_count == 0)
			break ;
		sleep_routine(philo);
		think_routine(philo);
	}
	free_tdata(data);
	exit(0);
}

void	eat_routine(t_philo *philo)
{
	int	target;

	target = get_ms_runtime() + philo->data->time_to_eat;
	is_dead(philo);
	print_log(philo->id, LOG_EAT);
	gettimeofday(&philo->last_meal_tv, NULL);
	while (get_ms_runtime() < target)
	{
		is_dead(philo);
		usleep(750);
	}
}

void	sleep_routine(t_philo *philo)
{
	int	target;

	target = get_ms_runtime() + philo->data->time_to_sleep;
	print_log(philo->id, LOG_SLEEP);
	while (get_ms_runtime() < target)
	{
		is_dead(philo);
		usleep(100);
	}
}

void	think_routine(t_philo *philo)
{
	print_log(philo->id, LOG_THINK);
	usleep(500);
	is_dead(philo);
}
