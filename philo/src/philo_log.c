# include <philosophers.h>

void ft_putnbr(long int number);
void ft_putstr(char *string);
void describe_philo(t_philo philo);

void print_log(int philo_id, char *action)
{
	long int timestamp;
	t_data *data;

	data = philo_init();
	(void) philo_id;
	(void) action;
	pthread_mutex_lock(&data->write_mutex);
	timestamp = get_ms_runtime();
	ft_putnbr(timestamp);
	ft_putstr(" ms ");
	ft_putnbr(philo_id);
	ft_putstr(action);
	pthread_mutex_unlock(&data->write_mutex);
}

void ft_putnbr(long int number)
{
	char c;
	if (number > 9)
		ft_putnbr(number / 10);
	c = number % 10 + '0';
	write(1, &c, 1);
}

void ft_putstr(char *string)
{
	if (!string)
		return;
	while(*string)
	{
		write(1, string, 1);
		string++;
	}
}

void describe_philo(t_philo philo)
{
	printf("Philo id         : %d\n", philo.id);
	// printf("Philo left_fork  : %d\n", philo.left_fork);
	// printf("Philo right_fork : %d\n", philo.right_fork);
	printf("Philo last meal  : %li\n", philo.last_meal_ms);
	printf("Philo meal count : %d\n", philo.meal_count);
}