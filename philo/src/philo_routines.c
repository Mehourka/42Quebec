/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:16 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/16 16:30:27 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void think_routine(t_data *data, int id)
{
	long int think_time;

	think_time = data->time_to.think;
	micro_sleep(think_time);
	printf("%ld ms %d is thinking\n", get_ms_runtime(), id);
}

void sleep_routine(t_data *data, int id)
{
	long int sleep_time;

	sleep_time = data->time_to.sleep; 
	micro_sleep(sleep_time);
	printf("%ld ms %d is sleeping\n", get_ms_runtime(), id);
}

void eat_routine(t_data *data, int id)
{
	long int eat_time;

	eat_time = data->time_to.eat; 
	micro_sleep(eat_time);
	printf("%ld ms %d is eating\n", get_ms_runtime(), id);
}

void *philo_routine(void *arg)
{
	t_data *data;
	t_philo *philo;

	data = philo_init();
	philo = arg;
	int id = philo->id;

	int i = 0;
	while(i < 2)
	{
		eat_routine(data, id);
		sleep_routine(data, id);
		think_routine(data, id);
		i++;
	}
	return (NULL);
}