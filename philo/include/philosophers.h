/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:31 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/23 11:22:26 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define PHILO_COUNT 1
# define TIMETO_DIE 420
# define TIMETO_EAT 69
# define TIMETO_SLEEP 69

# define LOG_FORK "has taken a fork"
# define LOG_EAT "is eating"
# define LOG_SLEEP "is sleeping"
# define LOG_THINK "is thinking"

# define MIN_ARG_NUM 5
# define MAX_ARG_NUM 6

typedef struct s_philo_times
{
	int			die;
	int			eat;
	int			sleep;
}						t_philo_times;

typedef struct s_philo
{
	int					id;
	pthread_t			thread;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
	struct timeval		last_meal_tv;
	int					is_full;

}	t_philo;

typedef struct s_data
{
	int					philo_count;
	int					meal_count;
	int					finished_eating;
	int					death;
	t_philo				*philosophers;
	pthread_mutex_t		*fork_mutex;
	pthread_mutex_t		write_mutex;
	pthread_mutex_t		status_mutex;
	t_philo_times		time_to;
}	t_data;

// Initialisation
t_data					*get_data(void);
int						philo_init(t_data *data, int argc, char *argv[]);

// Time functions
long int				delta_ms(struct timeval statrt, struct timeval end);
long int				get_ms_runtime(void);
void					micro_sleep(useconds_t milliseconds);
struct timeval			get_start_tv(void);
long int				get_tv_ms(struct timeval tv);

// Thread functions
void					detach_threads(t_data *data);

// Thread routines
void					*philo_routine(void *data);
void					death_loop(t_data *data);
int						inner_death_loop(t_data *data);
// Logs
void					ft_putnbr(long int number);
void					ft_putstr(char *string);
void					print_log(int philo_id, char *action);

// Memory managment
void					free_tdata(t_data *data);

// Parsing
int						parse_arguments(int argc, char *argv[], t_data *data);
int						is_dead(t_philo philo, t_data *data);
int						check_finished_eating(t_data *data);
# define STDOUT_FILENO 1
#endif