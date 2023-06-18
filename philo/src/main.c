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

void *test_routine(void *arg)
{
	(void) arg;
	printf("Philo in business\n");

	return (NULL);
}

void describe_philo(t_philo philo)
{
	printf("Philo id         : %d\n", philo.id);
	// printf("Philo left_fork  : %d\n", philo.left_fork);
	// printf("Philo right_fork : %d\n", philo.right_fork);
	printf("Philo last meal  : %li\n", philo.last_meal_ms);
	printf("Philo meal count : %d\n", philo.meal_count);
}

int main(void)
{
	t_data *data;
	t_philo *philosophers;

	int philo_count;
	int i = 0;

	data = philo_init();
	(void) data;
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
	printf("runtime : %li ms\n", get_ms_runtime());
	free_tdata();
}