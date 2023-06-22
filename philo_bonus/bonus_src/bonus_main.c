/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:12 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/22 14:54:14 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

void	*death_loop(void *arg);
void	*wait_children(void *arg);
int		check_finished_eating(t_data *data, int *flag);
void	create_children(t_data *data);
void	detach_threads(t_data *data);
void	kill_children(t_data *data);

int	main(int argc, char *argv[])
{
	t_data		*data;
	pthread_t	watcher;

	data = get_data();
	if (!data)
		return (1);
	if (philo_init(data, argc, argv))
		return (1);
	create_children(data);
	pthread_create(&watcher, NULL, wait_children, data);
	kill_children(data);
	free_tdata(data);
	return (0);
}

void create_children(t_data *data)
{
	int *pids;
	u_int32_t i;
	t_philo *philo;

	pids = data->pids;
	i = 0;
	while(i < data->philo_count)
	{
		philo = &data->philosophers[i];
		pids[i] = fork();
		if (pids[i] == 0)
		{
			// test_routine(philo);
			philo_routine(philo);
			return;
		}
		i++;git s
	}
}

void *wait_children(void *arg)
{
	int *pids;
	t_data *data;
	u_int32_t i;

	data = arg;
	pids = data->pids;
	i = 0;
	while(i < data->philo_count)
	{
		waitpid(-1, NULL, 0);
		i++;
	}
	sem_wait(data->write_sem);
	sem_post(data->state_sem);
	return (NULL);
}

void kill_children(t_data *data)
{
	// int *pids;
	u_int32_t i;

	// pids = data->pids;
	sem_wait(data->state_sem);
	i = 0;
	while(i < data->philo_count)
	{
		kill( data->pids[i], SIGKILL);
		i++;
	}
}


// void detach_threads(t_data *data)
// {
// 	t_philo		*philo;
// 	pthread_t	*thread;
// 	int			count;
// 	int			i;

// 	i = 0;
// 	count = data->philo_count;
// 	while (i < count)
// 	{
// 		philo = &data->philosophers[i];
// 		thread = &philo->thread;
// 		pthread_detach(*thread);
// 		i++;
// 	}
// }


void	*death_loop(void *arg)
{
	t_data	*data;

	data = arg;
	sem_wait(data->state_sem);
	kill_children(data);
	return (NULL);
}

int	is_dead(t_philo *philo)
{
	long int		time_to_die;
	struct timeval	last_meal;
	struct timeval	curr_time;
	t_data *data;

	data = philo->data;
	time_to_die = data->time_to.die;
	last_meal = philo->last_meal_tv;
	gettimeofday(&curr_time, NULL);
	
	if (delta_ms(last_meal, curr_time) > (int) time_to_die)
	{
		return (1);
	}
	return (0);
}

int	check_finished_eating(t_data *data, int *flag)
{
	int	bool;

	bool = 0;
	sem_wait(data->state_sem);
	if (data->finished_eating >= (int)data->philo_count)
	{
		bool ++;
		*flag = 1;
	}
	sem_post(data->state_sem);
	return (bool);
}
