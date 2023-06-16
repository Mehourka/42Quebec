#include "philosophers.h"

void	init_philo_threads(t_data *data);
void	init_philo_times(t_data *data);

t_data *philo_init(void)
{
	static t_data *data = NULL;

	if (!data)
	{
		// Init start runtime
		get_ms_runtime();

		// Init data structure
		data = malloc(sizeof(t_data));
		data->philo_count = 3;
		// init_philo_threads(data);
		init_philo_times(data);
	}
	return (data);
}

void	init_philo_threads(t_data *data)
{
	int philo_count;

	philo_count = data->philo_count;
	data->philo_threads = malloc(sizeof(pthread_t) * philo_count);
}

void	init_philo_times(t_data *data)
{
	data->time_to.die = 400;
	data->time_to.eat = 100;
	data->time_to.sleep = 100;
	data->time_to.think = 100;
}