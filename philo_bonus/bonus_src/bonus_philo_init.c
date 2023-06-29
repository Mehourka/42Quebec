/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philo_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:29 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/29 11:32:46 by kmehour          ###   ########.fr       */
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
	if (parse_arguments(argc, argv, data) != 0)
	{
		free(data);
		return (1);
	}
	data->pids = malloc(sizeof(int) * data->philo_count);
	init_semaforks(data);
	init_philosophers(data);
	return (0);
}

void	init_philosophers(t_data *data)
{
	t_philo	*philo;

	philo = &data->philosopher;
	philo->data = data;
}

void	init_semaforks(t_data *data)
{
	int	philo_count;

	philo_count = data->philo_count;
	sem_unlink(FORKS_SEM);
	sem_unlink(WRITE_SEM);
	data->sema_forks = sem_open(FORKS_SEM, O_CREAT | O_EXCL, 0644, philo_count);
	data->write_sem = sem_open(WRITE_SEM, O_CREAT | O_EXCL, 0644, 1);
}
