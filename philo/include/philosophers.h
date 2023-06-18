/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:31 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/16 16:30:32 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define PHILO_COUNT 2
# define TIMETO_DIE 400
# define TIMETO_EAT 100
# define TIMETO_SLEEP 100
# define TIMETO_THINK 100

# define LOG_FORK " took a fork\n"
# define LOG_EAT " is eating\n"
# define LOG_SLEEP " is sleeping\n"
# define LOG_THINK " is thinking\n"

typedef struct s_philo_times
{
	long int	die;
	long int	eat;
	long int	sleep;
	long int	think;
}	t_philo_times;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	long int		last_meal_ms;
	int				meal_count;

}	t_philo;

typedef struct s_data
{
	u_int32_t		philo_count;
	t_philo			*philosophers;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	write_mutex;
	t_philo_times	time_to;
}	t_data;


// Initialisation
t_data			*philo_init(void);

// Time functions
long int		delta_ms(struct timeval statrt, struct timeval end);
long int		get_ms_runtime(void);
void			micro_sleep(useconds_t milliseconds);

// Thread functions

// Thread routines
// void sleep_routine(t_data *data, t_philo *philo);
// void think_routine(t_data *data, t_philo *philo);
// void eat_routine(t_data *data, t_philo *philo);
void *philo_routine(void *data);

// Logs
void ft_putnbr(long int number);
void ft_putstr(char *string);
// void describe_philo(t_philo philo);
void print_log(int philo_id, char *action);

// Memory managment
void		free_tdata(void);

# define STDOUT_FILENO 1
#endif