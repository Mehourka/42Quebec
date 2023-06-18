/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:12 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/16 16:30:13 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"



int main(void)
{
	t_data *data;
	t_philo *philosophers;

	int philo_count;
	int i = 0;

	data = philo_init();
	philosophers = data->philosophers;
	philo_count = data->philo_count;

	while (i < philo_count)
	{
		pthread_create(&(philosophers[i].thread), NULL, philo_routine, &(philosophers[i]));
		i++;
	}

	i = 0;
	while (i < philo_count)
	{
		pthread_join(philosophers[i].thread, NULL);
		i++;
	}
	// printf("runtime : %li ms\n", get_ms_runtime());
	free_tdata();
}

