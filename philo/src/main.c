/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:12 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/19 17:46:03 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

int is_dead(t_philo philo, t_data *data);
void death_loop(t_data *data);

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

	philosophers = data->philosophers;
	philo_count = data->philo_count;
	while (i < philo_count)
	{
		pthread_create(&(philosophers[i].thread), NULL, philo_routine, &(philosophers[i]));
		i++;
	}

	death_loop(data);

	i = 0;
	while (i < philo_count)
	{
		pthread_detach(philosophers[i].thread);
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
	return (get_ms_runtime() - last_meal > time_to_die);
}

void death_loop(t_data *data)
{
	int i;
	int philo_count;
	t_philo *philosophers;
	int flag;

	flag = 0;
	philo_count = data->philo_count;
	philosophers = data->philosophers;
	while (!flag)
	{
		i = 0;
		while(i < philo_count)
		{
			if (is_dead(philosophers[i], data))
			{
				flag++;
				printf("%d has DIEDED !!!\n", philosophers[i].id);
				printf("last meal : %li current time : %li\n", philosophers[i].last_meal_ms, get_ms_runtime());
				break;
			}
			i++;
		}
		usleep(3000);
	}
	pthread_mutex_lock(&data->write_mutex);
	data->death = 1;
	pthread_mutex_unlock(&data->write_mutex);
}