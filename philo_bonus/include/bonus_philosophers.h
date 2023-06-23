/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philosophers.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:30:31 by kmehour           #+#    #+#             */
/*   Updated: 2023/06/23 10:27:57 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_PHILOSOPHERS_H
# define BONUS_PHILOSOPHERS_H

# include <limits.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>

# define PHILO_COUNT 2
# define TIMETO_DIE 420
# define TIMETO_EAT 69
# define TIMETO_SLEEP 69

# define LOG_FORK " took a fork\n"
# define LOG_EAT " is eating\n"
# define LOG_SLEEP " is sleeping\n"
# define LOG_THINK " is thinking\n"

# define MIN_ARG_NUM 5
# define MAX_ARG_NUM 6

# define FORKS_SEM "/semaforks"
# define WRITE_SEM "/writesem"
# define STATE_SEM "/statesem"

typedef struct s_philo_times
{
	u_int32_t			die;
	u_int32_t			eat;
	u_int32_t			sleep;
}						t_philo_times;

typedef struct s_philo
{
	int					id;
	struct s_data		*data;
	struct timeval		last_meal_tv;

}						t_philo;

typedef struct s_data
{
	u_int32_t			philo_count;
	u_int32_t			meal_count;
	t_philo				*philosophers;
	sem_t				*sema_forks;
	sem_t				*write_sem;
	sem_t				*state_sem;
	int					*pids;
	t_philo_times		time_to;
}						t_data;

// Initialisation
t_data					*get_data(void);
int						philo_init(t_data *data, int argc, char *argv[]);

// Time functions
long int				delta_ms(struct timeval statrt, struct timeval end);
long int				get_ms_runtime(void);
void					micro_sleep(useconds_t milliseconds);
struct timeval			get_start_tv(void);
int64_t					get_tv_ms(struct timeval tv);

// Thread routines
void					*philo_routine(void *data);

// Logs
void					ft_putnbr(long int number);
void					ft_putstr(char *string);
void					print_log(int philo_id, char *action);

// Memory managment
void					free_tdata(t_data *data);

// Parsing
int						parse_arguments(int argc, char *argv[], t_data *data);
int						is_dead(t_philo *philo);

#endif