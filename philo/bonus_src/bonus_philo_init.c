/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:29 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/20 18:19:02 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

void	init_philosophers(t_data *data);
void	init_philo_times(t_data *data);
void	init_semaforks(t_data *data);

t_data	*get_data(void)
{
	static t_data	*data = NULL;

	if (!data)
		data = malloc(sizeof(t_data));
	return (data);
}

int	philo_init(t_data *data, int argc, char *argv[])
{
	data->meal_count = -1;
	data->death = 0;
	data->finished_eating = 0;
	if (parse_arguments(argc, argv, data))
	{
		return (1);
	}
	data->pids = malloc(sizeof(int) * data->philo_count);
	init_semaforks(data);
	init_philosophers(data);
	get_start_tv();
	return (0);
}

void	init_philosophers(t_data *data)
{
	int	philo_count;
	t_philo *philo;
	int	i;

	philo_count = data->philo_count;
	data->philosophers = malloc(sizeof(t_philo) * philo_count);
	i = 0;
	while (i < philo_count)
	{
		philo = &data->philosophers[i];
		philo->id = i + 1;
		philo->data = data;
		philo->last_meal_tv.tv_sec = 0;
		philo->last_meal_tv.tv_usec = 0;
		i++;
	}
}

void	init_semaforks(t_data *data)
{
	int	philo_count;

	philo_count = data->philo_count;

	sem_unlink(FORKS_SEM);
	sem_unlink(WRITE_SEM);
	sem_unlink(STATE_SEM);
	data->sema_forks = sem_open(FORKS_SEM, O_CREAT | O_EXCL, 0644, philo_count);
	data->write_sem = sem_open(WRITE_SEM, O_CREAT | O_EXCL, 0644, 12);
	data->state_sem = sem_open(STATE_SEM, O_CREAT | O_EXCL, 0644, 12);
}