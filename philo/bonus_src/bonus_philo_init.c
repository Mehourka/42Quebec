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
	init_semaforks(data);
	init_philosophers(data);
	get_start_tv();
	return (0);
}

void	init_philosophers(t_data *data)
{
	int	philo_count;
	int	i;

	philo_count = data->philo_count;
	data->philosophers = malloc(sizeof(t_philo) * philo_count);
	i = 0;
	while (i < philo_count)
	{
		data->philosophers[i].id = i;
		data->philosophers[i].last_meal_tv = get_start_tv();
		data->philosophers[i].is_full = 0;
		i++;
	}
}

void	init_semaforks(t_data *data)
{
	int	philo_count;

	philo_count = data->philo_count;

	data->sema_forks = sem_open(FORKS_SEM, O_CREAT, O_RDWR, philo_count);
	data->write_sem = sem_open(WRITE_SEM, O_CREAT, O_RDWR, 1);
	data->state_sem = sem_open(STATE_SEM, O_CREAT, O_RDWR, 1);
	// sem_init(&data->sema_forks, 0, philo_count);
	// sem_init(&data->write_sem, 0, 1);
	// sem_init(&data->status_sem, 0, 1);
}
