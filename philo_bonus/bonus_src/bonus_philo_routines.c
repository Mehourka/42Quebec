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
		micro_sleep(data->time_to.eat / 2);
	while (data->meal_count != 0)
	{
		lock_forks(data->sema_forks, philo->id);
		is_dead(philo);
		eat_routine(philo);
		data->meal_count--;
		unlock_forks(data->sema_forks);
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
	long int	eat_time;
	int64_t	target;

	eat_time = philo->data->time_to.eat;
	target = get_ms_runtime() + eat_time;
	print_log(philo->id, LOG_EAT);
	gettimeofday(&philo->last_meal_tv, NULL);
	while (get_ms_runtime() < target)
	{
		is_dead(philo);
		usleep(500);
	}
	// micro_sleep(eat_time);
}

void	sleep_routine(t_philo *philo)
{
	long int	sleep_time;
	int64_t	target;

	sleep_time = philo->data->time_to.sleep;
	target = get_ms_runtime() + sleep_time;
	print_log(philo->id, LOG_SLEEP);
	while (get_ms_runtime() < target)
	{
		is_dead(philo);
		usleep(100);
	}

	// micro_sleep(sleep_time);
}

void	think_routine(t_philo *philo)
{
	print_log(philo->id, LOG_THINK);
	// usleep(500);
}
