# include "philosophers.h"

void sleep_routine(t_data *data);
void think_routine(t_data *data);
void eat_routine(t_data *data);
void philo_routine(t_data *data);

int main(void)
{
	t_data *data;

	data = philo_init();

	philo_routine(data);
	printf("runtime : %li\n", get_ms_runtime());
	free_tdata();
}

void think_routine(t_data *data)
{
	long int think_time;

	think_time = data->time_to.think;
	micro_sleep(think_time);
	printf("Philo %d thank %li ms\n", 0, think_time);
}

void sleep_routine(t_data *data)
{
	long int sleep_time;

	sleep_time = data->time_to.sleep; 
	micro_sleep(sleep_time);
	printf("Philo %d slept %li ms\n", 0, sleep_time);
}

void eat_routine(t_data *data)
{
	long int eat_time;

	eat_time = data->time_to.eat; 
	micro_sleep(eat_time);
	printf("Philo %d slept %li ms\n", 0, eat_time);
}

void philo_routine(t_data *data)
{
	sleep_routine(data);
	think_routine(data);
	eat_routine(data);
}