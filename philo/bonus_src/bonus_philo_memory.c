/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:21 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/20 17:51:49 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

void	destroy_mutex(t_data *data);

void	free_tdata(t_data *data)
{
	destroy_mutex(data);
	free(data->philosophers);
	free(data);
}

void	destroy_mutex(t_data *data)
{
	int				mutex_num;
	int				i;
	pthread_mutex_t	*mutex_arr;

	mutex_num = data->philo_count;
	mutex_arr = data->fork_mutex;
	i = 0;
	while (i < mutex_num)
	{
		pthread_mutex_destroy(&(mutex_arr[i]));
		i++;
	}
	pthread_mutex_destroy(&(data->write_mutex));
	pthread_mutex_destroy(&(data->status_mutex));
	free(mutex_arr);
}
