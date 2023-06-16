/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:21 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/16 16:30:22 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void destroy_mutex(t_data *data);

void free_tdata(void)
{
	t_data *data;

	data = philo_init();
	// free(data->philo_threads);
	destroy_mutex(data);
	free(data);
}

void destroy_mutex(t_data *data)
{
	int mutex_num;
	int i;
	pthread_mutex_t *mutex_arr;

	mutex_num = data->philo_count;
	mutex_arr = data->fork_mutex;
	i = 0;
	while(i < mutex_num)
	{
		pthread_mutex_destroy(&(mutex_arr[i]));
		i++;
	}
	free(mutex_arr);
}