/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:31 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/19 15:32:50 by kmehour          ###   ########.fr       */
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
# include <limits.h>

# define PHILO_COUNT 1
# define TIMETO_DIE 420
# define TIMETO_EAT 69
# define TIMETO_SLEEP 69

# define LOG_FORK " took a fork\n"
# define LOG_EAT " is eating\n"
# define LOG_SLEEP " is sleeping\n"
# define LOG_THINK " is thinking\n"

# define MIN_ARG_NUM 5
# define MAX_ARG_NUM 6

typedef struct s_philo_times
{
	u_int32_t	die;
	u_int32_t	eat;
	u_int32_t	sleep;
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
	int				death;
	t_philo			*philosophers;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	write_mutex;
	t_philo_times	time_to;
}	t_data;


// Initialisation
t_data			*get_data(void);
int				philo_init(t_data *data, int argc, char *argv[]);

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
void		free_tdata(t_data *data);

// Parsing
int parse_arguments(int argc, char *argv[], t_data *data);

# define STDOUT_FILENO 1
#endif