/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:12 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/20 17:18:40 by kmehour          ###   ########.fr       */
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

	// test_routine(data->philoso[1]);
	// return 0;
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
	long int time_to_die;
	struct timeval last_meal;
	struct timeval curr_time;

	pthread_mutex_lock(&data->status_mutex);
	if(philo.is_full)
	{
		pthread_mutex_unlock(&data->status_mutex);
		return (0);
	}
	pthread_mutex_unlock(&data->status_mutex);
		
	time_to_die = data->time_to.die;
	last_meal = philo.last_meal_tv;
	gettimeofday(&curr_time, NULL);
	// printf("start_time : %lli\n", get_tv_ms(get_start_tv()));
	// printf("Last meal : %lli\n", get_tv_ms(last_meal));
	// printf("Philo %d didnt eat in %li\n\n", philo.id, delta_ms(last_meal, curr_time));
	return (delta_ms(last_meal, curr_time) > time_to_die);
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
		usleep(50);
		i = 0;
		while(i < philo_count)
		{
			if (is_dead(philosophers[i], data))
			{
				flag++;
				// struct timeval start = get_start_tv();
				pthread_mutex_lock(&data->write_mutex);
				data->death = 1;
				printf("%li ms %d has died", get_ms_runtime(), i + 1);
				pthread_mutex_unlock(&data->write_mutex);
				break;
			}
			pthread_mutex_lock(&data->status_mutex);
			if(data->finished_eating >= philo_count)
			{
				flag++;
				pthread_mutex_unlock(&data->status_mutex);
				return;
			}
			pthread_mutex_unlock(&data->status_mutex);
			i++;
		}
	}
}