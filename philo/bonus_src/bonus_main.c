/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:12 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/20 17:59:22 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

void	death_loop(t_data *data);
int		check_finished_eating(t_data *data, int *flag);
void	create_children(t_data *data);
void	wait_children(t_data *data);
void	detach_threads(t_data *data);

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = get_data();
	if (!data)
		return (1);
	if (philo_init(data, argc, argv))
		return (1);
	create_children(data);
	// death_loop(data);
	wait_children(data);
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
		i++;
	}
}

void wait_children(t_data *data)
{
	// int *pids;
	u_int32_t i;

	// pids = data->pids;
	i = 0;
	while(i < data->philo_count)
	{
		waitpid( -1, NULL, 0);
		i++;
	}
}

// void creat_threads(t_data *data)
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
// 		pthread_create(thread, NULL, philo_routine, philo);
// 		// pthread_create(thread, NULL, test_routine, philo);
// 		i++;
// 	}
// }

// void join_threads(t_data *data)
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
// 		pthread_join(*thread, NULL);
// 		i++;
// 	}
// }

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


void	death_loop(t_data *data)
{
	int		i;
	int		philo_count;
	t_philo	*philosophers;
	int		flag;

	flag = 0;
	philo_count = data->philo_count;
	philosophers = data->philosophers;
	while (!flag)
	{
		usleep(50);
		i = 0;
		while (i < philo_count)
		{
			if (is_dead(&philosophers[i]))
			{
				// detach_threads(data);
				break ;
			}
			if (check_finished_eating(data, &flag))
				break ;
			i++;
		}
	}
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
	if (delta_ms(last_meal, curr_time) > time_to_die)
	{
		sem_wait(data->write_sem);
		data->death = 1;
		printf("%li ms %d has died\n", get_ms_runtime(), philo->id);
		sem_post(data->write_sem);
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