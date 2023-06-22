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
	if (philo->id % 2)
		micro_sleep(data->time_to.eat / 2);
	while (meal_count != 0)
	{
		sem_wait(data->write_sem);
		if (data->death)
		{
			sem_post(data->write_sem);
			break ;
		}
		sem_post(data->write_sem);
		lock_forks(data->sema_forks, philo->id);
		eat_routine(data, philo->id, &philo->last_meal_tv);
		meal_count--;
		unlock_forks(data->sema_forks);
		if (meal_count == 0)
			break;
		sleep_routine(data, philo->id);
		think_routine(data, philo->id);
	}
	sem_wait(data->state_sem);
	pthread_detach(checker);
	sem_post(data->state_sem);

	return (NULL);
}

void	*check_self(void* arg)
{
	t_philo *philo;

	philo = arg;
	while(1)
	{
		printf("Checking on %d\n", philo->id);
		break;
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
	usleep(50);
}

void	*test_routine(void *arg)
{
	t_data *data;
	t_philo *philo;

	data = get_data();
	philo = arg;
	int id = philo->id;
	// sem_t *write_sem = sem_open(WRITE_SEM, O_RDWR);

	// sem_t *write_sem = data->write_sem;
	if (id % 2 == 0)
	{
		printf("%li ms %d holds back\n", get_ms_runtime(), id);
		micro_sleep(data->time_to.eat / 2);
	}
	lock_forks(data->sema_forks,id);
	printf("%li ms %d started the routine\n", get_ms_runtime(), id);
	micro_sleep(data->time_to.eat);
	unlock_forks(data->sema_forks);
	return (NULL);
}