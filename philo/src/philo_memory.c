#include "philosophers.h"

void free_tdata(void)
{
	t_data *data;

	data = philo_init();
	free(data->philo_threads);
	free(data);
}