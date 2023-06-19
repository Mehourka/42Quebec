/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:12 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/19 15:33:32 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

int is_dead(t_philo philo, t_data *data);

int main(int argc, char *argv[])
{
	t_data *data;
	t_philo *philosophers;
	int philo_count;
	int i;

	i = 0;
	data = get_data();
	if (!data)
		return (1);
	
	if (philo_init(data, argc, argv))
		return (1);

	printf("Time to :\n%d\n%d\n%d\nCount %d\n", \
	data->time_to.die, data->time_to.eat, data->time_to.sleep, data->philo_count);

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
	free_tdata(data);
	return (0);
}

int is_dead(t_philo philo, t_data *data)
{
	long int last_meal;
	long int time_to_die;

	time_to_die = data->time_to.die;
	last_meal = philo.last_meal_ms;
	return (get_ms_runtime() - last_meal >= time_to_die);
}