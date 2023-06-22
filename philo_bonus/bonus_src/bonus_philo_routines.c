/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philo_routines.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:16 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/22 14:51:40 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

void	lock_forks(sem_t *sema_forks, int id);
void	unlock_forks(sem_t *sema_forks);
void	eat_routine(t_data *data, int id, struct timeval *last_meal_tv);
void	sleep_routine(t_data *data, int id);
void	think_routine(t_data *data, int id);
void	*check_self(void* arg);

void	*philo_routine(void *arg)
{
	t_data		*data;
	t_philo		*philo;
	int			meal_count;
	pthread_t	checker;

	data = get_data();
	philo = arg;
	meal_count = data->meal_count;

	pthread_create(&checker, NULL, check_self, (void*) philo);
	pthread_detach(checker);
	if (philo->id % 2 == 0)
		micro_sleep(data->time_to.eat / 2);
	while (meal_count != 0)
	{
		lock_forks(data->sema_forks, philo->id);
		eat_routine(data, philo->id, &philo->last_meal_tv);
		meal_count--;
		unlock_forks(data->sema_forks);
		if (meal_count == 0)
			break;
		sleep_routine(data, philo->id);
		think_routine(data, philo->id);
	}
	exit(0);
}

void	*check_self(void* arg)
{
	t_philo *philo;
	
	philo = arg;
	while(1)
	{
		usleep(1000);
		if(is_dead(philo))
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
	usleep(500);
}

# include <time.h>
# include <unistd.h>
void	*test_routine(void *arg)
{
	(void) arg;
	
	t_data		*data;
	t_philo		*philo;
	int			meal_count;
	pthread_t	checker;

	data = get_data();
	philo = arg;
	meal_count = data->meal_count;

	pthread_create(&checker, NULL, check_self, (void*) philo);
	pthread_detach(checker);

	int i = 1;
	while(i--)
	{
		sem_wait(data->write_sem);

		printf("%d Working\n", philo->id);
		sleep(1);
		
		sem_post(data->write_sem);
	}
	
	exit(0);
}
